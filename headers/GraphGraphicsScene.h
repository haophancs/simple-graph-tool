#ifndef GRAPHGRAPHICSSCENE_H
#define GRAPHGRAPHICSSCENE_H

#include "Graph.h"
#include "NodeGraphicsItem.h"
#include "ArcGraphicsItem.h"
#include <QGraphicsScene>
#include <QtWidgets>

enum GraphDemoFlag {
    OnlyNode, OnlyArc, ArcAndNode, Component, Coloring
};

class GraphGraphicsScene : public QGraphicsScene {
Q_OBJECT
public:
    GraphGraphicsScene();

    explicit GraphGraphicsScene(Graph *graph);

    Graph *getGraph() const;

    void setGraph(Graph *graph);

    friend class GraphGraphicsView;

public slots:

    void reloadData();

    void demoAlgorithm(std::list<std::pair<int, int>> listOfPairToDemo, GraphDemoFlag flag);

    void demoAlgorithm(const std::list<int> &listOfNumToDemo, GraphDemoFlag flag);

    void demoAlgorithm(const std::list<std::list<int>> &listOfListToDemo, GraphDemoFlag flag);

signals:

    void graphChanged();

    void needRedraw();

private:
    Graph *graph{};
    std::vector<NodeGraphicsItem *> nodeItems;
    std::vector<ArcGraphicsItem *> arcItems;

    int getArcId(int u, int v);

    std::unique_ptr<QTimer> unique_timer;

    std::list<int> listOfNum;
    std::list<std::list<int>> listOfList;
    std::list<std::pair<int, int>> listOfPair;

    void resetAfterDemoAlgo();
};

#endif // GRAPHGRAPHICSSCENE_H
