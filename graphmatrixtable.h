#ifndef GRAPHTABLE_H
#define GRAPHTABLE_H

#include "graph.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QKeyEvent>

class GraphMatrixTable : public QTableWidget
{
   Q_OBJECT
private:
    Graph *myGraph;
public:
    GraphMatrixTable();
    GraphMatrixTable(Graph *myGraph);
    void setGraph(Graph *myGraph);
    Graph* graph() const;
    void fittingResize();
    void defaultSetting();

signals:
    void graphChanged();

public slots:
    void adjustCell(int row, int column);
    void reloadData();
};

#endif // GRAPHMATRIXTABLE_H
