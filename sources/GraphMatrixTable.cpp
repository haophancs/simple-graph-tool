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

    this->graph = graph;
    if (graph == nullptr) return;
    reloadData();
}

Graph *GraphMatrixTable::getGraph() const {

    return this->graph;
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
                (graph->getArcWeight(row, column) != INT_MAX) ?
                QString::number(graph->getArcWeight(row, column))
                                                              : "inf");
    } else {
        if (data == "inf") {
            graph->removeArc(row, column);
            this->item(row, column)->setText(data);
        }
        graph->setArc(row, column, data.toInt());
        emit graphChanged();
        emit selectedArc(row, column);
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
    connect(this, &GraphMatrixTable::currentCellChanged, this, [this](int u, int v) {
        try {
            emit selectedArc(u, v);
        } catch (...) {}
    });
}

void GraphMatrixTable::reloadData() {

    disconnect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));

    this->clear();
    this->setRowCount(graph->getNodeNum());
    this->setColumnCount(graph->getNodeNum());
    QStringList table_header;
    for (const Node &node: graph->getNodeList()) {
        table_header << QString::fromStdString(node.getName());
    }
    this->setHorizontalHeaderLabels(table_header);
    this->setVerticalHeaderLabels(table_header);

    std::vector<std::vector<int>> adj_mat = graph->getAdjMatrix();
    for (int i = 0; i < graph->getNodeNum(); i++) {
        for (int j = 0; j < graph->getNodeNum(); j++) {

            this->setItem(i, j, new QTableWidgetItem);
            if (adj_mat[i][j] != INT_MAX) {

                this->item(i, j)->setText(QString::fromStdString(std::to_string(adj_mat[i][j])));
                if (i != j)
                    this->item(i, j)->setToolTip("Weight of the arc from node " +
                                                 QString::fromStdString(graph->getNode(i)->getName()) + " to node " +
                                                 QString::fromStdString(graph->getNode(j)->getName()));
            } else {
                this->item(i, j)->setText("inf");
                this->item(i, j)->setToolTip("No arc from node " +
                                             QString::fromStdString(graph->getNode(i)->getName()) + " to node " +
                                             QString::fromStdString(graph->getNode(j)->getName()));
            }
            this->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
        this->item(i, i)->setFlags(Qt::ItemIsEditable);
    }
    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
}
