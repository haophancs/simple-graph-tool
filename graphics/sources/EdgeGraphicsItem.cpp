#include "graphics/headers/EdgeGraphicsItem.h"
#include <qmath.h>
#include <QPen>
#include <QList>
#include <QPainter>
#include <utility>
#include "graphics/headers/GraphGraphicsScene.h"

EdgeGraphicsItem::EdgeGraphicsItem(GraphGraphicsScene *scene, NodeGraphicsItem *startItem, NodeGraphicsItem *endItem,
                                   QColor baseColor, QGraphicsItem *parent)
        : QGraphicsLineItem(parent) {
    this->_startItem = startItem;
    this->_endItem = endItem;
    this->_gscene = scene;
    this->_color = std::move(baseColor);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setAcceptHoverEvents(true);
    setPen(QPen(this->_color, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    this->_onSelectedColor = colorTable()[1];

    updatePosition();
    connect(startItem, SIGNAL(positionChanged()), SLOT(updatePosition()));
    connect(endItem, SIGNAL(positionChanged()), SLOT(updatePosition()));
    emit _gscene->needRedraw();
}

const QList<QColor> &EdgeGraphicsItem::colorTable() {
    static QList<QColor> colorTable;
    colorTable.append(QColor(57, 89, 119));
    colorTable.append(QColor(205, 92, 92));
    colorTable.append(QColor(57, 89, 119));
    colorTable.append(QColor(85, 107, 47));
    colorTable.append(QColor(47, 79, 79));
    colorTable.append(QColor(119, 136, 153));
    colorTable.append(QColor(112, 128, 144));
    return colorTable;
};

QColor EdgeGraphicsItem::defaultColor() { return colorTable()[0]; };

QColor EdgeGraphicsItem::defaultOnSelectedColor() { return colorTable()[1]; };

QRectF EdgeGraphicsItem::boundingRect() const {
    qreal extra = (pen().width() + 30) / 2.0;
    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
            .normalized()
            .adjusted(-extra, -extra, extra, extra);
}

QPainterPath EdgeGraphicsItem::shape() const {
    return this->_path;
}

GraphType::Edge EdgeGraphicsItem::edge() const {
    return _gscene->graph()->edge(_startItem->node(), _endItem->node());
}

int EdgeGraphicsItem::weight() const {
    return edge().weight();
}

void EdgeGraphicsItem::updatePosition() {
    qreal p = _startItem->pos().x();
    qreal q = _startItem->pos().y();
    qreal r = _endItem->pos().x();
    qreal s = _endItem->pos().y();
    qreal length_x = qFabs(p - r);
    qreal length_y = qFabs(q - s);
    qreal length = qSqrt(length_x * length_x + length_y * length_y);
    qreal tx1 = 1 - (_endItem->radius() / 2.) / length_x;
    qreal ty1 = 1 - (_endItem->radius() / 2.) / length_y;

    QPointF centerPos = QPoint(
            static_cast<int>((p + r) / 2),
            static_cast<int>((q + s) / 2));

    QLineF centerLine(mapFromItem(_startItem, 0, 0), mapFromItem(_endItem, 0, 0));
    setLine(centerLine);
    this->_path = QGraphicsLineItem::shape();

    QPointF arrowHeadPoint((1 - tx1) * p + tx1 * r, (1 - tx1) * q + tx1 * s);
    qreal arrowHeadSize = 15;
    qreal angle = std::atan2(line().dy(), -line().dx());
    if (std::abs(angle * 180 / M_PI) >= 45 && std::abs(angle * 180 / M_PI) <= 135) {
        arrowHeadPoint = QPointF(
                (1 - ty1) * p + ty1 * r,
                (1 - ty1) * q + ty1 * s);
    }
    if (_gscene->graph()->isDirected() && inversionAvailable()) {
        qreal offset = arrowHeadSize / 2;
        qreal foo = qMax(5., qMin(25., length / 6));
        if (edge().u()->name() < edge().v()->name()) {
            centerPos += QPointF(-foo, -foo);
            setLine(QLineF(line().p1(), line().p2() + QPointF(-4, -4)));
            arrowHeadPoint += QPointF(-offset, -offset);
        } else {
            centerPos += QPointF(foo, foo);
            setLine(QLineF(line().p1(), line().p2() + QPointF(4, 4)));
            arrowHeadPoint += QPointF(offset, offset);
        }

        QPainterPath tempPath(line().p1());
        tempPath.cubicTo(centerPos, centerPos, line().p2());
        QPainterPathStroker pathStroke;
        QPainterPath outline = pathStroke.createStroke(tempPath);
        this->_path = outline;
    }

    if (this->_gscene->graph()->isDirected()) {
        QPointF arrowP1 = arrowHeadPoint + QPointF(sin(angle + M_PI / 3) * arrowHeadSize,
                                                   cos(angle + M_PI / 3) * arrowHeadSize);
        QPointF arrowP2 = arrowHeadPoint + QPointF(sin(angle + M_PI - M_PI / 3) * arrowHeadSize,
                                                   cos(angle + M_PI - M_PI / 3) * arrowHeadSize);

        QPolygonF arrowHead;
        arrowHead << arrowHeadPoint << arrowP2 << arrowP1;
        this->_path.addPolygon(arrowHead);
    }
    if (_gscene->graph()->isWeighted()) {
        QFont font;
        font.setPointSize(13);
        auto textPos = centerPos;
        this->_path.addText(textPos, font, QString::number(this->weight()));
    }
    emit _gscene->needRedraw();
}

void EdgeGraphicsItem::setOnSelectedColor(QColor newColor) {
    this->_onSelectedColor = std::move(newColor);
}

bool EdgeGraphicsItem::inversionAvailable() const {
    return _gscene->graph()->hasEdge(edge().v(), edge().u());
}

void EdgeGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                             QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (_startItem->collidesWithItem(_endItem))
        return;

    painter->setTransform(transform(), true);
    //updatePosition();
    if (isSelected())
        _color = onSelectedColor();
    else
        _color = defaultColor();

    QPen myPen = pen();
    myPen.setColor(_color);
    myPen.setWidth(4);
    painter->setBrush(_color);
    painter->setPen(myPen);
    painter->drawPath(this->shape());
}

void EdgeGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsItem::hoverEnterEvent(event);
    setCursor(Qt::PointingHandCursor);
}


EdgeGraphicsItemCircle::EdgeGraphicsItemCircle(GraphGraphicsScene *scene, NodeGraphicsItem *startItem,
                                               GraphType::EdgeCircle *edge,
                                               QColor baseColor, QGraphicsItem *parent)
    : QGraphicsItem(parent) {

    this->_sourceItem = startItem;
    this->_gscene = scene;
    this->_color = std::move(baseColor);
    this->_radius = 70;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setAcceptHoverEvents(true);
    setCircle(edge);
    this->_onSelectedColor = EdgeGraphicsItem::colorTable()[1];

    updatePosition();
    connect(startItem, SIGNAL(positionChanged()), SLOT(updatePosition()));
    emit _gscene->needRedraw();
}

void EdgeGraphicsItemCircle::setCircle(GraphType::EdgeCircle *edge) {
    this->_edgeCircle = edge;

    this->setPos(this->_sourceItem->pos().x()-80,this->_sourceItem->pos().y()-10);

    _radius = std::max(_radius, _fontSize * (int) (5) / 2 + _fontSize);
}

QColor EdgeGraphicsItemCircle::defaultColor() { return EdgeGraphicsItem::colorTable()[0]; };

QColor EdgeGraphicsItemCircle::defaultOnSelectedColor() { return EdgeGraphicsItem::colorTable()[1]; };

QRectF EdgeGraphicsItemCircle::boundingRect() const {
    return {-_radius / 2. + .5,
        -_radius / 2. + .5,
        static_cast<qreal>(_radius + 10),
        static_cast<qreal>(_radius + 10)
    };
}


std::string EdgeGraphicsItemCircle::source() const {
    return _sourceItem->node()->name();
}

int EdgeGraphicsItemCircle::weight() const {

    std::string s = source();

    return _gscene->graph()->weightCircle(s);
}

void EdgeGraphicsItemCircle::updatePosition() {

    qreal p = _sourceItem->pos().x();
    qreal q = _sourceItem->pos().y();

    qreal offsetX = -85;
    qreal offsetY = -10;

    QPointF circleEdgePos(p + offsetX, q + offsetY);

    setPos(circleEdgePos);

    emit _gscene->needRedraw();

}

void EdgeGraphicsItemCircle::setOnSelectedColor(QColor newColor) {
    this->_onSelectedColor = std::move(newColor);
}


void EdgeGraphicsItemCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                                   QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (isSelected())
        _color = onSelectedColor();
    else
        _color = defaultColor();
    painter->setPen(QPen(Qt::black, 2, Qt::SolidLine));

    painter->drawEllipse(-_radius / 2, -_radius / 2, _radius, _radius);

    QFont font;
    font.setPixelSize(25);
    painter->setFont(font);
    QString txt = QString::number(this->weight());

    painter->drawText(- _fontSize * txt.length() / 4 + _fontSize / 8, _fontSize / 3, txt);

    qreal arrowHeadSize = 0.1;
    QPolygonF arrowHead = calculateArrowHead(arrowHeadSize);

    QPointF circleEdgePos(_sourceItem->pos() + QPointF(_radius, -_radius));

    painter->setBrush(_color);
    painter->drawPolygon(arrowHead);

}

void EdgeGraphicsItemCircle::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsItem::hoverEnterEvent(event);
    setCursor(Qt::PointingHandCursor);
}


QPolygonF EdgeGraphicsItemCircle::calculateArrowHead(qreal arrowHeadSize) {
    QPolygonF arrowHead;

    qreal angle = 0; // Starting angle for the arrow head
    qreal angleStep = 2 * M_PI / 3; // Step to create the three points of the arrow head

    for (int i = 0; i < 3; ++i) {
        qreal x = _radius * arrowHeadSize * cos(angle)+40; // Scale the x coordinate
        qreal y = _radius * arrowHeadSize * sin(angle)-20; // Scale the y coordinate
        arrowHead << QPointF(x, y);
        angle += angleStep;
    }

    return arrowHead;
}
