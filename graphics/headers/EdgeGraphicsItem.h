#ifndef EDGEGRAPHICSITEM_H
#define EDGEGRAPHICSITEM_H

#include <basis/headers/Edge.h>
#include "NodeGraphicsItem.h"

class QGraphicsLineItem;

class QGraphicsScene;

class QRectF;

class QGraphicsSceneMouseEvent;

class QPainterPath;

class GraphGraphicsScene;

class EdgeGraphicsItem : public QObject, public QGraphicsLineItem {
Q_OBJECT
public:
    enum {
        Type = UserType + 4
    };

    static const QList<QColor> &colorTable();

    static QColor defaultColor();

    static QColor defaultOnSelectedColor();

    EdgeGraphicsItem(GraphGraphicsScene *scene, NodeGraphicsItem *startItem, NodeGraphicsItem *endItem,
                     QColor color = defaultColor(),
                     QGraphicsItem *parent = nullptr);

    int type() const override { return Type; }

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    GraphType::Edge edge() const;

    bool inversionAvailable() const;

    int weight() const;

    void setOnSelectedColor(QColor color);

    QColor onSelectedColor() const { return this->_onSelectedColor; }

public slots:

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

private:
    GraphGraphicsScene *_gscene;
    NodeGraphicsItem *_startItem;
    NodeGraphicsItem *_endItem;
    QColor _color;
    QColor _onSelectedColor;
    QPainterPath _path;
};

#endif // EDGEGRAPHICSITEM_H
