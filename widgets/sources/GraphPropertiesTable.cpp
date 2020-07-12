#include "widgets/headers/GraphPropertiesTable.h"

GraphPropertiesTable::GraphPropertiesTable(GraphType::Graph *graph, int sectionSize) {
    setGraph(graph);
    this->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    this->verticalHeader()->setDefaultSectionSize(sectionSize);
    this->verticalHeader()->setCascadingSectionResizes(false);
    this->horizontalHeader()->setStretchLastSection(true);
    this->horizontalHeader()->hide();
}

void GraphPropertiesTable::setGraph(GraphType::Graph *graph) {
    this->_graph = graph;
    QStringList tableHeader;
    tableHeader << tr("Total node(s)") << tr("Total edge(s)") << tr("Weighted") << tr("Directed");
    this->setRowCount(4);
    this->setColumnCount(1);
    this->setVerticalHeaderLabels(tableHeader);

    for (int i = 0; i < this->rowCount(); ++i) {
        this->setItem(i, 0, new QTableWidgetItem());
        this->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        this->item(i, 0)->setFlags(Qt::ItemIsEnabled);
    }
    this->item(0, 0)->setText(QString::number(this->_graph->countNodes()));
    this->item(1, 0)->setText(QString::number(this->_graph->countEdges()));
    this->item(2, 0)->setText(QVariant(_graph->isWeighted()).toString());
    this->item(3, 0)->setText(QVariant(_graph->isDirected()).toString());
}

GraphPropertiesTable::GraphPropertiesTable(GraphType::Graph *graph) : GraphPropertiesTable(graph, 48) {}

void GraphPropertiesTable::onGraphChanged() {
    this->item(0, 0)->setText(QString::number(this->_graph->countNodes()));
    this->item(1, 0)->setText(QString::number(this->_graph->countEdges()));
}

