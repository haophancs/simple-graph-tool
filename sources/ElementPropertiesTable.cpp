#include "headers/ElementPropertiesTable.h"

ElementPropertiesTable::ElementPropertiesTable(Graph *graph, int sectionSize) {
    this->graph = graph;
    this->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    this->verticalHeader()->setDefaultSectionSize(sectionSize);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    this->verticalHeader()->setCascadingSectionResizes(false);
    this->horizontalHeader()->setStretchLastSection(true);
    this->horizontalHeader()->hide();
}

ElementPropertiesTable::ElementPropertiesTable(Graph *graph) : ElementPropertiesTable(graph, 48) {}

void ElementPropertiesTable::clearTable() {
    this->setRowCount(0);
    this->setColumnCount(0);
}

void ElementPropertiesTable::onGraphChanged() {
    clearTable();
}

void ElementPropertiesTable::onUnSelected() {
    clearTable();
}

void ElementPropertiesTable::onNodeSelected(int id) {
    clearTable();
    QStringList tableHeader;
    tableHeader << tr("Name") << tr("Positive degree") << tr("Negative degree");
    this->setRowCount(3);
    this->setColumnCount(1);
    this->setVerticalHeaderLabels(tableHeader);

    this->setItem(0, 0, new QTableWidgetItem());
    this->item(0, 0)->setText(QString::fromStdString(this->graph->getNodeName(id)));
    this->item(0, 0)->setFlags(Qt::ItemIsEnabled);
    this->item(0, 0)->setTextAlignment(Qt::AlignCenter);

    this->setItem(1, 0, new QTableWidgetItem());
    this->item(1, 0)->setText(QString::number(this->graph->getNode(id)->getPositiveDeg()));
    this->item(1, 0)->setFlags(Qt::ItemIsEnabled);
    this->item(1, 0)->setTextAlignment(Qt::AlignCenter);

    this->setItem(2, 0, new QTableWidgetItem());
    this->item(2, 0)->setText(QString::number(this->graph->getNode(id)->getNegativeDeg()));
    this->item(2, 0)->setFlags(Qt::ItemIsEnabled);
    this->item(2, 0)->setTextAlignment(Qt::AlignCenter);
}

void ElementPropertiesTable::onArcSelected(int u, int v) {
    clearTable();
    QStringList tableHeader;
    tableHeader << tr("From node") << tr("To node") << tr("Weight");
    this->setRowCount(3);
    this->setColumnCount(1);
    this->setVerticalHeaderLabels(tableHeader);

    this->setItem(0, 0, new QTableWidgetItem());
    this->item(0, 0)->setText(QString::fromStdString(this->graph->getNodeName(u)));
    this->item(0, 0)->setFlags(Qt::ItemIsEnabled);
    this->item(0, 0)->setTextAlignment(Qt::AlignCenter);

    this->setItem(1, 0, new QTableWidgetItem());
    this->item(1, 0)->setText(QString::fromStdString(this->graph->getNodeName(v)));
    this->item(1, 0)->setFlags(Qt::ItemIsEnabled);
    this->item(1, 0)->setTextAlignment(Qt::AlignCenter);

    this->setItem(2, 0, new QTableWidgetItem());
    this->item(2, 0)->setText((this->graph->getArcWeight(u, v) != INT_MAX) ?
                              QString::number(this->graph->getArcWeight(u, v))
                              : "inf");
    this->item(2, 0)->setFlags(Qt::ItemIsEnabled);
    this->item(2, 2)->setTextAlignment(Qt::AlignCenter);
}
