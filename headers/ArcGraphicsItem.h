#ifndef ARCITEM_H
#define ARCITEM_H

#include "NodeGraphicsItem.h"

class QGraphicsLineItem;

class QGraphicsScene;

class QRectF;

class QGraphicsSceneMouseEvent;

class QPainterPath;

class GraphGraphicsScene;

class ArcGraphicsItem : public QGraphicsLineItem {
public:
    enum {
        Type = UserType + 4
    };

    static const QList<QColor> &colorTable();

    static QColor defaultColor();

    static QColor defaultOnSelectedColor();

    ArcGraphicsItem(GraphGraphicsScene *scene, NodeGraphicsItem *startItem, NodeGraphicsItem *endItem,
                    QColor color = defaultColor(),
                    QGraphicsItem *parent = nullptr);

    int type() const override { return Type; }

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void setColor(const QColor &newColor) { this->color = newColor; }

    NodeGraphicsItem *getStartItem() const { return startItem; }

    NodeGraphicsItem *getEndItem() const { return endItem; }

    std::pair<int, int> arc() const;

    bool inversionAvailable() const;

    int weight();

    void updatePosition();

    QColor onSelectedColor() const;

    void setOnSelectedColor(QColor color);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

private:
    GraphGraphicsScene *myScene;
    NodeGraphicsItem *startItem;
    NodeGraphicsItem *endItem;
    QColor color;
    QColor selectedColor;
    QPolygonF arcHead;
    QPainterPath path;
};

#endif // ARCGRAPHICSITEM_H
