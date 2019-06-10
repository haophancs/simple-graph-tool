#include "arcgraphicsitem.h"
#include <qmath.h>
#include <QPen>
#include <QDebug>
#include <QtMath>
#include <QPainter>
#include "graphgraphicsscene.h"

ArcGraphicsItem::ArcGraphicsItem(GraphGraphicsScene *scene, NodeGraphicsItem *startItem, NodeGraphicsItem *endItem, QColor color, QGraphicsItem *parent)
    : QGraphicsLineItem(parent)
{
    this->myStartItem = startItem;
    this->myEndItem = endItem;
    this->myScene = scene;
    this->myColor = color;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setAcceptHoverEvents(true);
    setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    this->selectedColor = colorTable[1];
}

const QColor ArcGraphicsItem::colorTable[] = {
    QColor(57,89,119),
    QColor(205,92,92),
    QColor(85,107,47),
    QColor(47,79,79),
    QColor(119,136,153),
    QColor(112,128,144)
};
const QColor ArcGraphicsItem::defaultColor = colorTable[0];
const QColor ArcGraphicsItem::defaultOnSelectedColor = colorTable[1];

QRectF ArcGraphicsItem::boundingRect() const
{
    qreal extra = (pen().width() + 30) / 2.0;
    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

QPainterPath ArcGraphicsItem::shape() const
{
    QPainterPath path = myPath;// = QGraphicsLineItem::shape();
    path.addPolygon(arcHead);
    return path;
}

std::pair<int, int> ArcGraphicsItem::arc() const
{
    return std::make_pair(myStartItem->node()->getId(),
                          myEndItem->node()->getId());
}

int ArcGraphicsItem::weight()
{
    return myScene->graph()->getArcWeight(arc().first, arc().second);
}

void ArcGraphicsItem::updatePosition()
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    setLine(line);
}

QColor ArcGraphicsItem::onSelectedColor() const
{
    return this->selectedColor;
}

void ArcGraphicsItem::setOnSelectedColor(QColor color)
{
    this->selectedColor = color;
}

bool ArcGraphicsItem::inversionAvailable() const {

    return myScene->graph()->hasThisArc(arc().second, arc().first);
}

void ArcGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
          QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (myStartItem->collidesWithItem(myEndItem))
        return;

    painter->setTransform(transform(), true);

    qreal p = myStartItem->pos().x(); qreal q = myStartItem->pos().y();
    qreal r = myEndItem->pos().x(); qreal s = myEndItem->pos().y();
    qreal length_x = qFabs(p - r);
    qreal length_y = qFabs(q - s);
    qreal length = qSqrt(length_x*length_x + length_y*length_y);
    qreal tx1 = 1 - (NodeGraphicsItem::radius/2.) / length_x;
    qreal ty1 = 1 - (NodeGraphicsItem::radius/2.) / length_y;

    QPointF centerPos = QPoint(
                (p + r) / 2,
                (q + s) / 2);

    QLineF centerLine(myStartItem->pos(), myEndItem->pos());
    setLine(centerLine);

    QPointF arcPoint((1-tx1)*p + tx1*r, (1-tx1)*q + tx1*s);
    double angle = std::atan2(line().dy(), -line().dx());
    if (std::abs(angle*180/M_PI) >= 52 && std::abs(angle*180/M_PI) <= 128) {
        arcPoint = QPointF(
                    (1-ty1)*p + ty1*r,
                    (1-ty1)*q + ty1*s);
    }

    qreal arcHeadSize = 10;
    if (!inversionAvailable()) {
        myPath = QGraphicsLineItem::shape();
    }
    else {
        qreal offset = 4;
        if (length < 350) {
            offset += ((350 - length) / 100) * 4;
            angle -= ((350 - length / 100)) * (4/180) * M_PI;
        }
        qreal foo = qMax(5., qMin(25., length / 3));
        if (arc().first < arc().second) {
            centerPos += QPointF(-foo, -foo);
            setLine(QLineF(line().p1(), line().p2() + QPointF(-4, -4)));
            arcPoint += QPointF(-offset, -offset);
        }
        else {
            centerPos += QPointF(foo, foo);
            setLine(QLineF(line().p1(), line().p2() + QPointF(4, 4)));
            arcPoint += QPointF(offset, offset);
        }

        QPainterPath path(line().p1());
        path.cubicTo(centerPos, centerPos, line().p2());
        QPainterPathStroker stroker;
        QPainterPath outline = stroker.createStroke(path);
        myPath = outline;
    }
    QPointF arcP1 = arcPoint + QPointF(sin(angle + M_PI / 3) * arcHeadSize,
                                    cos(angle + M_PI / 3) * arcHeadSize);
    QPointF arcP2 = arcPoint + QPointF(sin(angle + M_PI - M_PI / 3) * arcHeadSize,
                                    cos(angle + M_PI - M_PI / 3) * arcHeadSize);

    arcHead.clear();
    arcHead << arcPoint << arcP2 << arcP1;

    if (isSelected())
        myColor = onSelectedColor();
    else
        myColor = defaultColor;

    QPen myPen = pen();
    myPen.setColor(myColor);
    myPen.setWidth(4);
    painter->setBrush(myColor);
    painter->setPen(myPen);
    painter->drawPolygon(arcHead);
    painter->drawPath(myPath);

    QString weight = QString::number(this->weight());
    QFont font = painter->font(); font.setPointSize(18);
    painter->setFont(font);
    painter->drawText(centerPos + ((arc().first < arc().second)? QPointF(-4, -4) : QPointF(4, 4)), weight);
}

void ArcGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsItem::hoverEnterEvent(event);
    setCursor(Qt::PointingHandCursor);
}

