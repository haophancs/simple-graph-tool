#include "headers/NodeGraphicsItem.h"
#include "headers/GraphGraphicsScene.h"
#include <QtWidgets>
#include <QDebug>
#include <utility>

int NodeGraphicsItem::radius = 80;

NodeGraphicsItem::NodeGraphicsItem(GraphGraphicsScene *scene, Node *node, QColor color) {
    this->myScene = scene;
    this->color = std::move(color);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setAcceptHoverEvents(true);
    setNode(node);
    isMoving = false;
    selectedColor = defaultOnSelectedColor();
}

void NodeGraphicsItem::setNode(Node *newNode) {
    this->node = newNode;
    this->setPos(newNode->getEuclidePos());
    radius = std::max(radius, 20 + (int) newNode->getName().length() * 10);
}

Node *NodeGraphicsItem::getNode() const {
    return this->node;
}

QRectF NodeGraphicsItem::boundingRect() const {
    return {-radius / 2. + .5,
            -radius / 2. + .5,
            static_cast<qreal>(radius + 4),
            static_cast<qreal>(radius + 4)
    };
}

const QList<QColor> &NodeGraphicsItem::colorTable() {
    static QList<QColor> colorTable = {
            QColor(244, 164, 96),
            QColor(50, 205, 50),
            QColor(230, 230, 250),
            QColor(244, 164, 96),
            QColor(245, 222, 179),
            QColor(221, 160, 221),
            QColor(135, 206, 235),
            QColor(240, 230, 140),
            QColor(255, 165, 0),
            QColor(240, 255, 255),
            QColor(0, 255, 255),
            QColor(255, 255, 0),
            QColor(240, 255, 255),
            QColor(255, 228, 225),
            QColor(220, 220, 220),
            QColor(176, 196, 222)
    };
    return colorTable;
};

QColor NodeGraphicsItem::defaultColor() { return colorTable()[0]; }

QColor NodeGraphicsItem::defaultOnSelectedColor() { return colorTable()[1]; }

void NodeGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (isSelected())
        color = onSelectedColor();
    else
        color = defaultColor();
    painter->setPen(QPen(Qt::black, 2, Qt::SolidLine));
    painter->setBrush(QBrush(color));
    painter->drawEllipse(-radius / 2, -radius / 2, radius, radius);

    QFont font;
    font.setPixelSize(20);
    painter->setFont(font);
    QString txt = QString::fromStdString(this->getNode()->getName());
    painter->drawText(-4 * txt.length(), 5, txt);
}

void NodeGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
                .length() < QApplication::startDragDistance()) {
        return;
    }
    isMoving = true;
    setCursor(Qt::ClosedHandCursor);
    setPos(event->scenePos());
    this->getNode()->setEuclidePos(this->pos());
    emit myScene->needRedraw();
    emit positionChanged();
    QGraphicsItem::mouseMoveEvent(event);
}

void NodeGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseReleaseEvent(event);
    if (isMoving) {
        setSelected(false);
        isMoving = false;
    }
    emit this->myScene->graphChanged();
    setCursor(Qt::OpenHandCursor);
}

void NodeGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsItem::hoverEnterEvent(event);
    setCursor(Qt::PointingHandCursor);
}

QColor NodeGraphicsItem::getColor() const {

    return this->color;
}

QColor NodeGraphicsItem::onSelectedColor() const {
    return this->selectedColor;
}

