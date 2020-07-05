#ifndef GRAPHPROPERTIESTABLE_H
#define GRAPHPROPERTIESTABLE_H

#include <QTableWidget>
#include <QHeaderView>
#include "basis/headers/Graph.h"

class GraphPropertiesTable : public QTableWidget {
Q_OBJECT

public:
    explicit GraphPropertiesTable(GraphType::Graph *graph, int sectionSize);

    explicit GraphPropertiesTable(GraphType::Graph *graph);

    void setGraph(GraphType::Graph *graph);

private:
    GraphType::Graph *_graph;

public slots:

    void onGraphChanged();
};


#endif //GRAPHPROPERTIESTABLE_H
