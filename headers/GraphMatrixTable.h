#ifndef GRAPHTABLE_H
#define GRAPHTABLE_H

#include "Graph.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QKeyEvent>

class GraphMatrixTable : public QTableWidget {
Q_OBJECT
private:
    GraphType::Graph *_graph{};
    GraphType::AdjacencyMatrix* _adj{};
    int sectionSize;

public:
    explicit GraphMatrixTable(GraphType::Graph *graph, int sectionSize = 80);

    void defaultSetting();

    void setGraph(GraphType::Graph *myGraph);

    GraphType::Graph *graph() const;

signals:

    void graphChanged();

    void arcSelected(std::string uname, std::string vname);

public slots:

    void adjustCell(int row, int column);

    void reload();
};

#endif // GRAPHMATRIXTABLE_H
