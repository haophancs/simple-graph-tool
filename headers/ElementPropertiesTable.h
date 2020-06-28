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

    void onNodeSelected(const std::string& node_name);

    void onArcSelected(const std::string& uname, const std::string& vname);

    void onUnSelected();
};


#endif //ELEMENTTABLEWIDGET_H
