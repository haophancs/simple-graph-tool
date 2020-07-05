#ifndef GRAPHGRAPHICSSCENE_H
#define GRAPHGRAPHICSSCENE_H

#include "basis/headers/Graph.h"
#include "NodeGraphicsItem.h"
#include "EdgeGraphicsItem.h"
#include <QGraphicsScene>
#include <QtWidgets>

enum GraphDemoFlag {
    OnlyNode, OnlyEdge, EdgeAndNode, Component, Coloring
};

class GraphGraphicsScene : public QGraphicsScene {
Q_OBJECT
public:
    GraphGraphicsScene();

    explicit GraphGraphicsScene(GraphType::Graph *graph);

    GraphType::Graph *graph() const;

    void setGraph(GraphType::Graph *graph);

    void clearAll();

    friend class GraphGraphicsView;

    ~GraphGraphicsScene() override;

public slots:

    void reload();

    void setInterval(int interval) {
        this->_interval = interval;
        if (_uniqueTimer)
            this->_uniqueTimer->setInterval(interval);
    }

    void demoAlgorithm(const std::list<std::pair<std::string, std::string>> &listOfPairToDemo, GraphDemoFlag flag);

    void demoAlgorithm(const std::list<std::string> &listOfNodeToDemo, GraphDemoFlag flag);

    void demoAlgorithm(const std::list<std::list<std::string>> &listOfListToDemo, GraphDemoFlag flag);

signals:

    void graphChanged();

    void needRedraw();

private:

    using QGraphicsScene::clear;

    GraphType::Graph *_graph{};
    std::unordered_map<std::string, NodeGraphicsItem *> _nodeItems;
    std::unordered_map<std::pair<std::string, std::string>, EdgeGraphicsItem *> _edgeItems;

    EdgeGraphicsItem *edgeItem(const std::string &uname, const std::string &vname);

    NodeGraphicsItem *nodeItem(const std::string &name);

    std::unique_ptr<QTimer> _uniqueTimer;
    std::list<std::string> _listOfNode;
    std::list<std::list<std::string>> _listOfList;
    std::list<std::pair<std::string, std::string>> _listOfPair;
    int _interval;

    void resetAfterDemoAlgo();
};

#endif // GRAPHGRAPHICSSCENE_H
