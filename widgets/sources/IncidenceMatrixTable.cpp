#include "widgets/headers/IncidenceMatrixTable.h"
#include <QDebug>

void IncidenceMatrixTable::defaultSetting() {
    this->horizontalHeader()->setMinimumSectionSize(this->_sectionSize);
    this->horizontalHeader()->setDefaultSectionSize(this->_sectionSize);
    this->horizontalHeader()->setCascadingSectionResizes(false);
    this->verticalHeader()->setMinimumSectionSize(this->_sectionSize);
    this->verticalHeader()->setDefaultSectionSize(this->_sectionSize);
    this->verticalHeader()->setCascadingSectionResizes(false);
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
}

void IncidenceMatrixTable::setGraph(GraphType::Graph *graph) {

    this->_graph = graph;
    if (graph == nullptr) return;
    reload();
}

GraphType::Graph *IncidenceMatrixTable::graph() const {
    return this->_graph;
}

void IncidenceMatrixTable::adjustCell(int row, int column) {

}

IncidenceMatrixTable::IncidenceMatrixTable(GraphType::Graph *graph, int sectionSize) : _sectionSize(sectionSize) {
    defaultSetting();
    setGraph(graph);
    connect(this, &IncidenceMatrixTable::currentCellChanged, this, [this](int row, int col) {
        if (row >= 0 && col >= 0 && row < rowCount() && col < columnCount()) {
            emit edgeSelected(_incidence->edges()[col].u()->name(), _incidence->edges()[col].v()->name());
        }
    });
}

void IncidenceMatrixTable::reload() {

    disconnect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
    this->clear();
    delete this->_incidence;

    this->_incidence = new GraphType::IncidenceMatrix(_graph->incidenceMatrix());
    this->setRowCount(_incidence->nodes().size());
    this->setColumnCount(_incidence->edges().size());
    QStringList h_header, v_header;
    for (const auto &edge: _incidence->edges())
        h_header << QString::fromStdString(edge.u()->name() + "-" + edge.v()->name());
    for (const auto &node: _incidence->nodes())
        v_header << QString::fromStdString(node->name());
    this->setHorizontalHeaderLabels(h_header);
    this->setVerticalHeaderLabels(v_header);

    for (int i = 0; i < _incidence->nodes().size(); ++i) {
        for (int j = 0; j < _incidence->edges().size(); ++j) {
            this->setItem(i, j, new QTableWidgetItem);
            this->item(i, j)->setTextAlignment(Qt::AlignCenter);
            this->item(i, j)->setText(QString::number(_incidence->value(i, j)));
            this->item(i, j)->setFlags(this->item(i, j)->flags() ^ Qt::ItemIsEditable);
        }
    }
    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(adjustCell(int, int)));
}

