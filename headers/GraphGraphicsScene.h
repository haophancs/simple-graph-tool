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

    Graph *graph() const;

    void setGraph(Graph *graph);

    void clearAll();

    friend class GraphGraphicsView;

    ~GraphGraphicsScene() override;

public slots:

    void reload();

    void demoAlgorithm(const std::list<std::pair<std::string, std::string>>& listOfPairToDemo, GraphDemoFlag flag);

   void demoAlgorithm(const std::list<std::string> &listOfNodeToDemo, GraphDemoFlag flag);

    void demoAlgorithm(const std::list<std::list<std::string>> &listOfListToDemo, GraphDemoFlag flag);

signals:

    void graphChanged();

    void needRedraw();

private:

    using QGraphicsScene::clear;

    Graph *_graph{};
    std::unordered_map<std::string, NodeGraphicsItem *> _nodeItems;
    std::unordered_map<std::pair<std::string, std::string>, ArcGraphicsItem *> _arcItems;

    ArcGraphicsItem *arcItem(const std::string& uname, const std::string& vname);
    NodeGraphicsItem *nodeItem(const std::string &name);

    std::unique_ptr<QTimer> _uniqueTimer;
    std::list<std::string> _listOfNode;
    std::list<std::list<std::string>> _listOfList;
    std::list<std::pair<std::string, std::string>> _listOfPair;

    void resetAfterDemoAlgo();
};

#endif // GRAPHGRAPHICSSCENE_H
