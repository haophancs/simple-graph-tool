#ifndef ARCITEM_H
#define ARCITEM_H

#include "nodegraphicsitem.h"

class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;

class GraphGraphicsScene;

class ArcGraphicsItem : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };
    static const QColor colorTable[];
    static const QColor defaultColor;
    static const QColor defaultOnSelectedColor;

    ArcGraphicsItem(GraphGraphicsScene *scene, NodeGraphicsItem *startItem, NodeGraphicsItem *endItem, QColor color = defaultColor,
      QGraphicsItem *parent = 0);

    int type() const override { return Type; }
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setColor(const QColor &color) { myColor = color; }
    NodeGraphicsItem *startItem() const { return myStartItem; }
    NodeGraphicsItem *endItem() const { return myEndItem; }

    std::pair<int, int> arc() const;
    bool inversionAvailable() const;
    int weight();
    void updatePosition();

    QColor onSelectedColor() const;
    void setOnSelectedColor(QColor color);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

private:
    GraphGraphicsScene *myScene;
    NodeGraphicsItem *myStartItem;
    NodeGraphicsItem *myEndItem;
    QColor myColor;
    QColor selectedColor;
    QPolygonF arcHead;
    QPainterPath myPath;
};

#endif // ARCGRAPHICSITEM_H
