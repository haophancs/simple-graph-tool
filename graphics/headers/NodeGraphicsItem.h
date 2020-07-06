#ifndef NODEGRAPHICSITEM_H
#define NODEGRAPHICSITEM_H

#include "basis/headers/Node.h"
#include <QGraphicsItem>

class GraphGraphicsScene;

class NodeGraphicsItem : public QObject, public QGraphicsItem {
Q_OBJECT
public:
    NodeGraphicsItem(GraphGraphicsScene *scene, GraphType::Node *node, QColor color = colorTable()[0]);

    static const QList<QColor> &colorTable();

    static QColor defaultColor();

    static QColor defaultOnSelectedColor();

    enum {
        Type = UserType + 5
    };

    int type() const override { return Type; }

    void setNode(GraphType::Node *_node);

    GraphType::Node *node() const;

    int radius() const { return this->_radius; }

    QColor onSelectedColor() const;

    QColor color() const { return this->_color; };

    void setColor(const QColor &newColor) { this->_color = newColor; }

    void setOnSelectedColor(const QColor &newColor) { this->_selectedColor = newColor; }

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:

    void positionChanged();

private:
    int _radius;
    GraphType::Node *_node{};
    QColor _color;
    QColor _selectedColor;
    GraphGraphicsScene *_gscene;
    bool _isMoving;
    const int _fontSize = 10;
    const QString _font = "Source Code Pro";

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif // NODEGRAPHICSITEM_H
