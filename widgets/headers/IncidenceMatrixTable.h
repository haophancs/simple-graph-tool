#ifndef INCIDENCEMATRIXTABLE_H
#define INCIDENCEMATRIXTABLE_H

#include "basis/headers/Graph.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QKeyEvent>

class IncidenceMatrixTable : public QTableWidget {
Q_OBJECT
private:
    GraphType::Graph *_graph{};
    GraphType::IncidenceMatrix *_incidence{};
    int _sectionSize;

public:
    explicit IncidenceMatrixTable(GraphType::Graph *graph, int sectionSize = 80);

    void defaultSetting();

    void setGraph(GraphType::Graph *myGraph);

    GraphType::Graph *graph() const;

signals:

    void graphChanged();

    void edgeSelected(std::string uname, std::string vname);

public slots:

    void reload();

    void adjustCell(int row, int column);
};

#endif //INCIDENCEMATRIXTABLE_H
