#ifndef GRAPHGRAPHICSVIEW_H
#define GRAPHGRAPHICSVIEW_H

#include "graphgraphicsscene.h"
#include <QGraphicsView>
#include <QContextMenuEvent>
#include <QMenu>
class GraphGraphicsView : public QGraphicsView
{
    Q_OBJECT
private:
    GraphGraphicsScene *myScene;
    QMenu *contextMenu;
    bool moving;
    bool selectTargetNode;
    bool isRunningAlgoDemo;
    NodeGraphicsItem *itemFrom;
    qreal currentScale;
    const qreal scaleMax = 1.;
    const qreal scaleMin = 0.3;
public:
    GraphGraphicsView();
    ~GraphGraphicsView();
    void setScene(GraphGraphicsScene *scene);

public slots:
    void redraw();

protected:
    void wheelEvent(QWheelEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    void unSelect();
    void selectedNode(int id);
    void selectedArc(int u, int v);
    void addNewNode(QPointF newNodePos);
    void removeNode(int id);
    void editNode(int id);
    void isolateNode(int id);
    void addArcFrom(int id);
    void startAlgorithm(QString algo, int id);
    void removeArc(int u, int v);
    void addNewArc();
    void setArc(int u, int v);

    void needRefresh();
};

#endif // GRAPHGRAPHICSVIEW_H
