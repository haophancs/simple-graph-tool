#ifndef ARCITEM_H
#define ARCITEM_H

#include "NodeGraphicsItem.h"

class QGraphicsLineItem;

class QGraphicsScene;

class QRectF;

class QGraphicsSceneMouseEvent;

class QPainterPath;

class GraphGraphicsScene;

class ArcGraphicsItem : public QObject, public QGraphicsLineItem {
Q_OBJECT
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

    std::pair<int, int> arc() const;

    bool inversionAvailable() const;

    int weight() const;

    void setOnSelectedColor(QColor color);

    QColor getOnSelectedColor() const { return this->onSelectedColor; }

public slots:
    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

private:
    GraphGraphicsScene *myScene;
    NodeGraphicsItem *startItem;
    NodeGraphicsItem *endItem;
    QColor color;
    QColor onSelectedColor;
    QPainterPath path;
};

#endif // ARCGRAPHICSITEM_H
