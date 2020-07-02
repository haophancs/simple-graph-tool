#ifndef ELEMENTTABLEWIDGET_H
#define ELEMENTTABLEWIDGET_H

#include <QTableWidget>
#include <QHeaderView>
#include "basis/headers/Graph.h"

class ElementPropertiesTable : public QTableWidget {
Q_OBJECT

public:
    explicit ElementPropertiesTable(GraphType::Graph *graph, int sectionSize);

    explicit ElementPropertiesTable(GraphType::Graph *graph);

private:
    GraphType::Graph *_graph;

    void clearTable();

public slots:

    void onGraphChanged();

    void onNodeSelected(const std::string &node_name);

    void onEdgeSelected(const std::string &uname, const std::string &vname);

    void onUnSelected();

    void setGraph(GraphType::Graph *graph);
};


#endif //ELEMENTTABLEWIDGET_H
