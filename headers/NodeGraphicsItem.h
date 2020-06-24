#ifndef NODEGRAPHICSITEM_H
#define NODEGRAPHICSITEM_H

#include "Node.h"
#include <QGraphicsItem>

class GraphGraphicsScene;

class NodeGraphicsItem : public QObject, public QGraphicsItem {
Q_OBJECT
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

    void setNode(Node *newNode);

    Node *getNode() const;

    QColor onSelectedColor() const;

    QColor getColor() const;

    void setColor(const QColor &newColor) { this->color = newColor; }

    void setOnSelectedColor(const QColor &newColor) { this->selectedColor = newColor; }

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:
    void positionChanged();

private:
    Node *node{};
    QColor color;
    QColor selectedColor;
    GraphGraphicsScene *myScene;
    bool isMoving;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

};

#endif // NODEGRAPHICSITEM_H
