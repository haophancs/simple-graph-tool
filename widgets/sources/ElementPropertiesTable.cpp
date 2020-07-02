#include "widgets/headers/ElementPropertiesTable.h"

ElementPropertiesTable::ElementPropertiesTable(GraphType::Graph *graph, int sectionSize) {
    this->_graph = graph;
    this->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    this->verticalHeader()->setDefaultSectionSize(sectionSize);
    this->verticalHeader()->setCascadingSectionResizes(false);
    this->horizontalHeader()->setStretchLastSection(true);
    this->horizontalHeader()->hide();
}

ElementPropertiesTable::ElementPropertiesTable(GraphType::Graph *graph) : ElementPropertiesTable(graph, 48) {}

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

void ElementPropertiesTable::onNodeSelected(const std::string& node_name) {
    clearTable();
    QStringList tableHeader;
    tableHeader << tr("Name") << tr("Positive degree") << tr("Negative degree");
    this->setRowCount(3);
    this->setColumnCount(1);
    this->setVerticalHeaderLabels(tableHeader);

    this->setItem(0, 0, new QTableWidgetItem());
    this->item(0, 0)->setTextAlignment(Qt::AlignCenter);
    this->item(0, 0)->setText(QString::fromStdString(node_name));
    this->item(0, 0)->setFlags(Qt::ItemIsEnabled);

    this->setItem(1, 0, new QTableWidgetItem());
    this->item(1, 0)->setTextAlignment(Qt::AlignCenter);
    this->item(1, 0)->setText(QString::number(this->_graph->node(node_name)->positiveDegree()));
    this->item(1, 0)->setFlags(Qt::ItemIsEnabled);

    this->setItem(2, 0, new QTableWidgetItem());
    this->item(2, 0)->setTextAlignment(Qt::AlignCenter);
    this->item(2, 0)->setText(QString::number(this->_graph->node(node_name)->negativeDegree()));
    this->item(2, 0)->setFlags(Qt::ItemIsEnabled);
}

void ElementPropertiesTable::onEdgeSelected(const std::string& uname, const std::string& vname) {
    clearTable();
    QStringList tableHeader;
    tableHeader << tr("From node") << tr("To node") << tr("Weight");
    this->setRowCount(3);
    this->setColumnCount(1);
    this->setVerticalHeaderLabels(tableHeader);

    this->setItem(0, 0, new QTableWidgetItem());
    this->item(0, 0)->setTextAlignment(Qt::AlignCenter);
    this->item(0, 0)->setText(QString::fromStdString(uname));
    this->item(0, 0)->setFlags(Qt::ItemIsEnabled);

    this->setItem(1, 0, new QTableWidgetItem());
    this->item(1, 0)->setTextAlignment(Qt::AlignCenter);
    this->item(1, 0)->setText(QString::fromStdString(vname));
    this->item(1, 0)->setFlags(Qt::ItemIsEnabled);

    this->setItem(2, 0, new QTableWidgetItem());
    this->item(2, 0)->setTextAlignment(Qt::AlignCenter);
    this->item(2, 0)->setText((this->_graph->weight(uname, vname) != INT_MAX) ?
                              QString::number(this->_graph->weight(uname, vname))
                                                                              : "inf");
    this->item(2, 0)->setFlags(Qt::ItemIsEnabled);
}
