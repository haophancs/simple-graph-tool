#include "widgets/headers/AdjacencyMatrixTable.h"
#include <QMessageBox>
#include <QDebug>

void AdjacencyMatrixTable::defaultSetting() {

    this->horizontalHeader()->setMinimumSectionSize(this->_sectionSize);
    this->horizontalHeader()->setDefaultSectionSize(this->_sectionSize);
    this->horizontalHeader()->setCascadingSectionResizes(false);
    this->verticalHeader()->setMinimumSectionSize(this->_sectionSize);
    this->verticalHeader()->setDefaultSectionSize(this->_sectionSize);
    this->verticalHeader()->setCascadingSectionResizes(false);
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
}

void AdjacencyMatrixTable::setGraph(GraphType::Graph *graph) {

    this->_graph = graph;
    if (graph == nullptr) return;
    reload();
}

GraphType::Graph *AdjacencyMatrixTable::graph() const {
    return this->_graph;
}

void AdjacencyMatrixTable::adjustCell(int row, int column) {

    bool out_of_range = false;
    std::string _strInvalidVal = _graph->invalidValue() != INT_MAX ? std::to_string(_graph->invalidValue()) : "inf";
    QRegExp re("\\d*");
    QString data = this->item(row, column)->text();
    data = data.trimmed();
    if (data.isNull() || data.isNull() || data == "")
        data = QString::fromStdString(_strInvalidVal);

    bool is_invalid_value = data == QString::fromStdString(_strInvalidVal);

    if (re.exactMatch(data)) {
        if (data == QString::number(_adj->value(row, column))) return;
        out_of_range = (data.toLongLong() < _graph->weightRange().first ||
                        data.toLongLong() > _graph->weightRange().second);
    } else if (data != QString::fromStdString(_strInvalidVal))
        out_of_range = true;

    if (out_of_range && !is_invalid_value) {
        QMessageBox msgWarning;

        QString msg;
        msg.sprintf("Weight value of the Edge(u, v) must be a NUMBER\n"
                    "in range [%d, %d]\n"
                    "To remove the edge, enter \"%s\"",
                    _graph->weightRange().first, _graph->weightRange().second, _strInvalidVal.c_str());

        msgWarning.setText(msg);
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Error");
        msgWarning.exec();
        this->item(row, column)->setText(
                (_adj->value(row, column) != INT_MAX) ?
                QString::number(_adj->value(row, column)) : "inf");
    } else {
        if (is_invalid_value)
            _graph->removeEdge(_adj->node(row), _adj->node(column));
        else
            _graph->setEdge(_adj->node(row), _adj->node(column), data.toInt());
        if (this->item(column, row) != this->item(row, column)) {
            delete _adj;
            _adj = new GraphType::AdjacencyMatrix(_graph->adjMatrix());
            if (_graph->isUndirected()) {
                auto old_item = this->item(column, row);
                auto new_item = new QTableWidgetItem(*old_item);
                new_item->setText((_adj->value(column, row) != INT_MAX) ?
                                  QString::number(_adj->value(column, row)) : "inf");
                this->removeCellWidget(column, row);
                this->setItem(column, row, new_item);
            }
        }
        emit graphChanged();
    }
}

AdjacencyMatrixTable::AdjacencyMatrixTable(GraphType::Graph *graph, int sectionSize) : _sectionSize(sectionSize) {
    defaultSetting();
    setGraph(graph);

    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
    connect(this, &QTableWidget::itemSelectionChanged, this, [this]() {
        for (QTableWidgetItem *item : this->selectedItems())
            adjustCell(item->row(), item->column());
    });
    connect(this, &AdjacencyMatrixTable::currentCellChanged, this, [this](int row, int col) {
        if (row >= 0 && col >= 0 && row < rowCount() && col < columnCount()) {
            emit edgeSelected(_adj->node(row)->name(), _adj->node(col)->name());
        }
    });
}

void AdjacencyMatrixTable::reload() {

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

    for (int i = 0; i < _adj->nodes().size(); ++i) {
        for (int j = 0; j < _adj->nodes().size(); ++j) {
            this->setItem(i, j, new QTableWidgetItem);
            if (_adj->value(i, j) != _graph->invalidValue()) {
                this->item(i, j)->setText(QString::number(_adj->value(i, j)));
                if (i != j)
                    this->item(i, j)->setToolTip("Weight of the edge from node " +
                                                 QString::fromStdString(_adj->node(i)->name()) + " to node " +
                                                 QString::fromStdString(_adj->node(j)->name()));
            } else {
                this->item(i, j)->setText(_graph->invalidValue() == INT_MAX ? "inf" : QString::number(_adj->value(i, j)));
                this->item(i, j)->setToolTip("No edge from node " +
                                             QString::fromStdString(_adj->node(i)->name()) + " to node " +
                                             QString::fromStdString(_adj->node(j)->name()));
            }
            this->item(i, j)->setTextAlignment(Qt::AlignCenter);
            if (this->_graph->isUndirected() && j < i)
                this->item(i, j)->setFlags(Qt::ItemIsEditable);
        }
        this->item(i, i)->setFlags(Qt::ItemIsEditable);
    }
    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
}

