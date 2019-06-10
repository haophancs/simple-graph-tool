#ifndef NODEGRAPHICSITEM_H
#define NODEGRAPHICSITEM_H

#include "node.h"
#include <QGraphicsItem>

class GraphGraphicsScene;

class NodeGraphicsItem : public QGraphicsItem
{
public:
    enum { Type = UserType + 5 };
    NodeGraphicsItem(GraphGraphicsScene *scene, Node *node, QColor color = colorTable[0]);
    int type() const override { return Type; }
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setNode(Node *myNode);
    Node* node() const;

    void setColor(QColor color);
    QColor color() const;
    QColor onSelectedColor() const;
    void setOnSelectedColor(QColor color);

    static int radius;
    static const QColor colorTable[];
    static const QColor defaultColor;
    static const QColor defaultOnSelectedColor;

private:
    Node *myNode;
    QColor myColor;
    QColor selectedColor;
    GraphGraphicsScene *myScene;
    bool isMoving;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif // NODEGRAPHICSITEM_H
