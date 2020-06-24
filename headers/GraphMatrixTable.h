#ifndef GRAPHTABLE_H
#define GRAPHTABLE_H

#include "Graph.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QKeyEvent>

class GraphMatrixTable : public QTableWidget {
Q_OBJECT
private:
    Graph *myGraph{};
    int sectionSize;

public:
    explicit GraphMatrixTable(Graph *myGraph, int sectionSize = 80);

    void defaultSetting();

    void setGraph(Graph *myGraph);

    Graph *getGraph() const;

signals:

    void graphChanged();

    void selectedArc(int u, int v);

public slots:

    void adjustCell(int row, int column);

    void reloadData();
};

#endif // GRAPHMATRIXTABLE_H
