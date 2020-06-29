#ifndef GRAPHPROPERTIESTABLE_H
#define GRAPHPROPERTIESTABLE_H
#include <QTableWidget>
#include <QHeaderView>
#include "Graph.h"

class GraphPropertiesTable : public QTableWidget {
    Q_OBJECT

public:
    explicit GraphPropertiesTable(Graph *graph, int sectionSize);

    explicit GraphPropertiesTable(Graph *graph);

private:
    Graph *_graph;

public slots:

    void onGraphChanged();
};


#endif //GRAPHPROPERTIESTABLE_H
