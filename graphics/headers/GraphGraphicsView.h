#ifndef GRAPHGRAPHICSVIEW_H
#define GRAPHGRAPHICSVIEW_H

#include "GraphGraphicsScene.h"
#include <QGraphicsView>
#include <QContextMenuEvent>
#include <QMenu>

enum StartAlgoFlag {
    DFS, BFS, Dijkstra, AStar, Prim, ST_DFS, ST_BFS
};

class GraphGraphicsView : public QGraphicsView {
Q_OBJECT
private:
    GraphGraphicsScene *_gcene{};
    QMenu *_contextMenu{};
    bool _moving;
    bool _selectTargetNode;
    bool _isRunningAlgoDemo;
    NodeGraphicsItem *_startItem{};
    qreal _currentScale;
    const qreal _scaleMax = 1.5;

public:
    GraphGraphicsView();

    void setScene(GraphGraphicsScene *scene);

public slots:

    void redraw();

protected:
    void wheelEvent(QWheelEvent *event) override;

    void contextMenuEvent(QContextMenuEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

signals:

    void unSelected();

    void nodeSelected(std::string node_name);

    void nodeAdded(QPointF pos, bool auto_naming);

    void nodeRemoved(std::string node_name);

    void nodeEdited(std::string node_name);

    void nodeIsolated(std::string node_name);

    void edgeAddedFrom(std::string node_name);

    void startAlgorithm(StartAlgoFlag algo_flag, std::string source_name);

    void edgeSelected(std::string uname, std::string vname);

    void edgeRemoved(std::string uname, std::string vname);

    void edgeAdded();

    void edgeSet(std::string uname, std::string vname);

    void needRefresh();
};

#endif // GRAPHGRAPHICSVIEW_H
