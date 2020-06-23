#ifndef ELEMENTTABLEWIDGET_H
#define ELEMENTTABLEWIDGET_H

#include <QTableWidget>
#include <QHeaderView>
#include "Graph.h"

class ElementPropertiesTable : public QTableWidget {
Q_OBJECT

public:
    explicit ElementPropertiesTable(Graph *graph, int sectionSize);

    explicit ElementPropertiesTable(Graph *graph);

private:
    Graph *graph;

    void clearTable();

public slots:

    void onGraphChanged();

    void onNodeSelected(int id);

    void onArcSelected(int u, int v);

    void onUnSelected();
};


#endif //ELEMENTTABLEWIDGET_H
