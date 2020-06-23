#ifndef NODEGRAPHICSITEM_H
#define NODEGRAPHICSITEM_H

#include "Node.h"
#include <QGraphicsItem>

class GraphGraphicsScene;

class NodeGraphicsItem : public QGraphicsItem {
public:
    NodeGraphicsItem(GraphGraphicsScene *scene, Node *node, QColor color = colorTable()[0]);

    static int radius;

    static const QList<QColor> &colorTable();

    static QColor defaultColor();

    static QColor defaultOnSelectedColor();

    enum {
        Type = UserType + 5
    };

    int type() const override { return Type; }

    void setNode(Node *myNode);

    Node *node() const;

    QColor color() const;

    QColor onSelectedColor() const;

    void setColor(const QColor &color) { myColor = color; }

    void setOnSelectedColor(const QColor &color) { selectedColor = color; }

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    Node *myNode{};
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
