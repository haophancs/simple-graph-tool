#include "graphics/headers/NodeGraphicsItem.h"
#include "graphics/headers/GraphGraphicsScene.h"
#include <QtWidgets>
#include <QDebug>
#include <utility>


NodeGraphicsItem::NodeGraphicsItem(GraphGraphicsScene *scene, GraphType::Node *node, QColor color) {
    this->_gscene = scene;
    this->_color = std::move(color);
    this->_radius = 80;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setAcceptHoverEvents(true);
    setNode(node);
    _isMoving = false;
    _selectedColor = defaultOnSelectedColor();
}

void NodeGraphicsItem::setNode(GraphType::Node *node) {
    this->_node = node;
    this->setPos(_node->euclidePos());
    QFontMetrics fm(QFont(_font, _fontSize));
    _radius = std::max(_radius, fm.width(QString::fromStdString(_node->name() + "  ")));
}

GraphType::Node *NodeGraphicsItem::node() const {
    return this->_node;
}

QRectF NodeGraphicsItem::boundingRect() const {
    return {-_radius / 2. + .5,
            -_radius / 2. + .5,
            static_cast<qreal>(_radius + 4),
            static_cast<qreal>(_radius + 4)
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
        _color = onSelectedColor();
    else
        _color = defaultColor();
    painter->setPen(QPen(Qt::black, 2, Qt::SolidLine));
    painter->setBrush(QBrush(_color));
    painter->drawEllipse(-_radius / 2, -_radius / 2, _radius, _radius);

    QFont font(_font, _fontSize);
    painter->setFont(font);
    QString txt = QString::fromStdString(this->node()->name());
    QFontMetrics fm(font);
    painter->drawText(-fm.width(txt) / 2, fm.height() / 3, txt);
}

void NodeGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
                .length() < QApplication::startDragDistance()) {
        return;
    }
    _isMoving = true;
    setCursor(Qt::ClosedHandCursor);
    setPos(event->scenePos());
    this->node()->setEuclidePos(this->pos());
    emit _gscene->needRedraw();
    emit positionChanged();
    QGraphicsItem::mouseMoveEvent(event);
}

void NodeGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseReleaseEvent(event);
    if (_isMoving) {
        setSelected(false);
        _isMoving = false;
    }
    //emit this->_gscene->graphChanged();
    setCursor(Qt::OpenHandCursor);
}

void NodeGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsItem::hoverEnterEvent(event);
    setCursor(Qt::PointingHandCursor);
}

QColor NodeGraphicsItem::onSelectedColor() const {
    return this->_selectedColor;
}

