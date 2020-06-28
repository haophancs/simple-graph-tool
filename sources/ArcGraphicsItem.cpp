#include "headers/ArcGraphicsItem.h"
#include <qmath.h>
#include <QPen>
#include <QList>
#include <QPainter>
#include <utility>
#include "headers/GraphGraphicsScene.h"

ArcGraphicsItem::ArcGraphicsItem(GraphGraphicsScene *scene, NodeGraphicsItem *startItem, NodeGraphicsItem *endItem,
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

const QList<QColor> &ArcGraphicsItem::colorTable() {
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

QColor ArcGraphicsItem::defaultColor() { return colorTable()[0]; };

QColor ArcGraphicsItem::defaultOnSelectedColor() { return colorTable()[1]; };

QRectF ArcGraphicsItem::boundingRect() const {
    qreal extra = (pen().width() + 30) / 2.0;
    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
            .normalized()
            .adjusted(-extra, -extra, extra, extra);
}

QPainterPath ArcGraphicsItem::shape() const {
    return this->_path;
}

std::pair<std::string, std::string> ArcGraphicsItem::arc() const {
    return std::make_pair(_startItem->node()->name(),
                          _endItem->node()->name());
}

int ArcGraphicsItem::weight() const {
    return _gscene->graph()->weight(arc().first, arc().second);
}

void ArcGraphicsItem::updatePosition() {
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

    QPointF arcHeadPoint((1 - tx1) * p + tx1 * r, (1 - tx1) * q + tx1 * s);
    qreal arcHeadSize = 15;
    qreal angle = std::atan2(line().dy(), -line().dx());
    if (std::abs(angle * 180 / M_PI) >= 45 && std::abs(angle * 180 / M_PI) <= 135) {
        arcHeadPoint = QPointF(
                (1 - ty1) * p + ty1 * r,
                (1 - ty1) * q + ty1 * s);
    }
    if (inversionAvailable()) {
        angle = std::atan2(line().dy(), -line().dx());
        qreal offset = arcHeadSize / 2;
        qreal foo = qMax(5., qMin(25., length / 6));
        if (arc().first < arc().second) {
            centerPos += QPointF(-foo, -foo);
            setLine(QLineF(line().p1(), line().p2() + QPointF(-4, -4)));
            arcHeadPoint += QPointF(-offset, -offset);
        } else {
            centerPos += QPointF(foo, foo);
            setLine(QLineF(line().p1(), line().p2() + QPointF(4, 4)));
            arcHeadPoint += QPointF(offset, offset);
        }

        QPainterPath tempPath(line().p1());
        tempPath.cubicTo(centerPos, centerPos, line().p2());
        QPainterPathStroker pathStroke;
        QPainterPath outline = pathStroke.createStroke(tempPath);
        this->_path = outline;
    }

    QPointF arcP1 = arcHeadPoint + QPointF(sin(angle + M_PI / 3) * arcHeadSize,
                                       cos(angle + M_PI / 3) * arcHeadSize);
    QPointF arcP2 = arcHeadPoint + QPointF(sin(angle + M_PI - M_PI / 3) * arcHeadSize,
                                       cos(angle + M_PI - M_PI / 3) * arcHeadSize);

    QPolygonF arcHead;
    arcHead << arcHeadPoint << arcP2 << arcP1;
    this->_path.addPolygon(arcHead);

    QFont font;
    font.setPointSize(13);
    auto textPos = centerPos;
    this->_path.addText(textPos, font, QString::number(this->weight()));
    emit _gscene->needRedraw();
}

void ArcGraphicsItem::setOnSelectedColor(QColor newColor) {
    this->_onSelectedColor = std::move(newColor);
}

bool ArcGraphicsItem::inversionAvailable() const {

    return _gscene->graph()->hasArc(arc().second, arc().first);
}

void ArcGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
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

void ArcGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsItem::hoverEnterEvent(event);
    setCursor(Qt::PointingHandCursor);
}

