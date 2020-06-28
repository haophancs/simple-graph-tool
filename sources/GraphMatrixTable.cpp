#include "headers/GraphMatrixTable.h"
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

void GraphMatrixTable::setGraph(Graph *graph) {

    this->_graph = graph;
    if (graph == nullptr) return;
    reload();
}

Graph *GraphMatrixTable::graph() const {
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
        msgWarning.setText("Weight value of the Arc(u, v) with u != v "
                           "\nmust be a NUMBER that greater than 0!\n"
                           "\nTo remove the arc, enter \"inf\" "
                           "\nor a number that greater than " + QString::number(INT_MAX));
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Error");
        msgWarning.exec();
        this->item(row, column)->setText(
                (_graph->weight(_adj.nodes[row], _adj.nodes[column]) != INT_MAX) ?
                QString::number(_graph->weight(_adj.nodes[row], _adj.nodes[column]))
                                                         : "inf");
    } else {
        if (data == "inf") {
            _graph->removeArc(_adj.nodes[row], _adj.nodes[column]);
            this->item(row, column)->setText(data);
        }
        _graph->setArc(_adj.nodes[row], _adj.nodes[column], data.toInt());
        emit graphChanged();
        emit arcSelected(_adj.nodes[row]->name(), _adj.nodes[column]->name());
    }
}

GraphMatrixTable::GraphMatrixTable(Graph *myGraph, int sectionSize) : sectionSize(sectionSize) {
    defaultSetting();
    setGraph(myGraph);

    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
    connect(this, &QTableWidget::itemSelectionChanged, this, [this]() {
        for (QTableWidgetItem *item : this->selectedItems())
            adjustCell(item->row(), item->column());
    });
    connect(this, &GraphMatrixTable::currentCellChanged, this, [this](int row, int col) {
        try {
            emit arcSelected(_adj.nodes[row]->name(), _adj.nodes[col]->name());
        } catch (...) {}
    });
}

void GraphMatrixTable::reload() {

    disconnect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
    //this->clear();
    this->_adj = _graph->adjMatrix();
    this->setRowCount(_graph->countNodes());
    this->setColumnCount(_graph->countNodes());
    QStringList table_header;
    for (const auto &node: _adj.nodes)
        table_header << QString::fromStdString(node->name());
    this->setHorizontalHeaderLabels(table_header);
    this->setVerticalHeaderLabels(table_header);

    for (int i = 0; i < _adj.matrix.size(); i++) {
        for (int j = 0; j < _adj.matrix.size(); j++) {

            this->setItem(i, j, new QTableWidgetItem);
            if (_adj.matrix[i][j] != INT_MAX) {
                this->item(i, j)->setText(QString::fromStdString(std::to_string(_adj.matrix[i][j])));
                if (i != j)
                    this->item(i, j)->setToolTip("Weight of the arc from node " +
                                                 QString::fromStdString(_adj.nodes[i]->name()) + " to node " +
                                                 QString::fromStdString(_adj.nodes[j]->name()));
            } else {
                this->item(i, j)->setText("inf");
                this->item(i, j)->setToolTip("No arc from node " +
                                             QString::fromStdString(_adj.nodes[i]->name())+ " to node " +
                                             QString::fromStdString(_adj.nodes[j]->name()));
            }
            this->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
        this->item(i, i)->setFlags(Qt::ItemIsEditable);
    }
    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
}
