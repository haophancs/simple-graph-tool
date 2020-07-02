#include "widgets/headers/GraphMatrixTable.h"
#include <QMessageBox>
#include <QDebug>

void GraphMatrixTable::defaultSetting() {

    this->horizontalHeader()->setMinimumSectionSize(this->sectionSize);
    this->horizontalHeader()->setDefaultSectionSize(this->sectionSize);
    this->horizontalHeader()->setCascadingSectionResizes(false);
    this->verticalHeader()->setMinimumSectionSize(this->sectionSize);
    this->verticalHeader()->setDefaultSectionSize(this->sectionSize);
    this->verticalHeader()->setCascadingSectionResizes(false);
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
}

void GraphMatrixTable::setGraph(GraphType::Graph *graph) {

    this->_graph = graph;
    if (graph == nullptr) return;
    reload();
}

GraphType::Graph *GraphMatrixTable::graph() const {
    return this->_graph;
}

void GraphMatrixTable::adjustCell(int row, int column) {

    bool invalid = false;

    QRegExp re("\\d*");
    QString data = this->item(row, column)->text();
    data = data.trimmed();
    if (data.isNull() || data.isNull() || data == "")
        data = "inf";

    if (re.exactMatch(data)) {
        if (data.toLongLong() <= 0)
            invalid = true;
        else if (data.toLongLong() >= INT_MAX) {
            data = "inf";
        }
    } else if (data != "inf")
        invalid = true;

    if (invalid) {
        QMessageBox msgWarning;
        msgWarning.setText("Weight value of the Edge(u, v) with u != v "
                           "\nmust be a NUMBER that greater than 0!\n"
                           "\nTo remove the edge, enter \"inf\" "
                           "\nor a number that greater than " + QString::number(INT_MAX));
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Error");
        msgWarning.exec();
        this->item(row, column)->setText(
                (_adj->weight(row, column)!= INT_MAX) ?
                QString::number(_adj->weight(row, column))
                                                         : "inf");
    } else {
        if (data == "inf") {
            _graph->removeEdge(_adj->node(row), _adj->node(column));
            this->item(row, column)->setText(data);
        }
        _graph->setEdge(_adj->node(row), _adj->node(column), data.toInt());
        emit graphChanged();
        emit edgeSelected(_adj->node(row)->name(), _adj->node(column)->name());
    }
}

GraphMatrixTable::GraphMatrixTable(GraphType::Graph *graph, int sectionSize) : sectionSize(sectionSize) {
    defaultSetting();
    setGraph(graph);

    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
    connect(this, &QTableWidget::itemSelectionChanged, this, [this]() {
        for (QTableWidgetItem *item : this->selectedItems())
            adjustCell(item->row(), item->column());
    });
    connect(this, &GraphMatrixTable::currentCellChanged, this, [this](int row, int col) {
        if (row >= 0 && col >= 0 && row < _adj->nodes().size() && col < _adj->nodes().size())
            emit edgeSelected(_adj->node(row)->name(), _adj->node(col)->name());
    });
}

void GraphMatrixTable::reload() {

    disconnect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
    this->clear();
    delete this->_adj;
    this->_adj = new GraphType::AdjacencyMatrix(_graph->adjMatrix());
    this->setRowCount(_graph->countNodes());
    this->setColumnCount(_graph->countNodes());
    QStringList table_header;
    for (const auto &node: _adj->nodes())
        table_header << QString::fromStdString(node->name());
    this->setHorizontalHeaderLabels(table_header);
    this->setVerticalHeaderLabels(table_header);

    for (int i = 0; i < _adj->nodes().size(); i++) {
        for (int j = 0; j < _adj->nodes().size(); j++) {

            this->setItem(i, j, new QTableWidgetItem);
            if (_adj->weight(i, j) != INT_MAX) {
                this->item(i, j)->setText(QString::fromStdString(std::to_string(_adj->weight(i, j))));
                if (i != j)
                    this->item(i, j)->setToolTip("Weight of the edge from node " +
                                                 QString::fromStdString(_adj->node(i)->name()) + " to node " +
                                                 QString::fromStdString(_adj->node(i)->name()));
            } else {
                this->item(i, j)->setText("inf");
                this->item(i, j)->setToolTip("No edge from node " +
                                             QString::fromStdString(_adj->node(i)->name())+ " to node " +
                                             QString::fromStdString(_adj->node(i)->name()));
            }
            this->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
        this->item(i, i)->setFlags(Qt::ItemIsEditable);
    }
    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
}
