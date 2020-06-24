#include "headers/ArcGraphicsItem.h"
#include <qmath.h>
#include <QPen>
#include <QList>
#include <QPainter>
#include <utility>
#include "headers/GraphGraphicsScene.h"

ArcGraphicsItem::ArcGraphicsItem(GraphGraphicsScene *scene, NodeGraphicsItem *startItem, NodeGraphicsItem *endItem,
                                 QColor color, QGraphicsItem *parent)
        : QGraphicsLineItem(parent) {
    this->startItem = startItem;
    this->endItem = endItem;
    this->myScene = scene;
    this->color = std::move(color);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setAcceptHoverEvents(true);
    setPen(QPen(color, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    this->selectedColor = colorTable()[1];
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
    QPainterPath path = path;// = QGraphicsLineItem::shape();
    path.addPolygon(arcHead);
    return path;
}

std::pair<int, int> ArcGraphicsItem::arc() const {
    return std::make_pair(startItem->getNode()->getId(),
                          endItem->getNode()->getId());
}

int ArcGraphicsItem::weight() {
    return myScene->getGraph()->getArcWeight(arc().first, arc().second);
}

void ArcGraphicsItem::updatePosition() {
    QLineF line(mapFromItem(startItem, 0, 0), mapFromItem(endItem, 0, 0));
    setLine(line);
}

QColor ArcGraphicsItem::onSelectedColor() const {
    return this->selectedColor;
}

void ArcGraphicsItem::setOnSelectedColor(QColor color) {
    this->selectedColor = std::move(color);
}

bool ArcGraphicsItem::inversionAvailable() const {

    return myScene->getGraph()->hasThisArc(arc().second, arc().first);
}

void ArcGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                            QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (startItem->collidesWithItem(endItem))
        return;

    painter->setTransform(transform(), true);

    qreal p = startItem->pos().x();
    qreal q = startItem->pos().y();
    qreal r = endItem->pos().x();
    qreal s = endItem->pos().y();
    qreal length_x = qFabs(p - r);
    qreal length_y = qFabs(q - s);
    qreal length = qSqrt(length_x * length_x + length_y * length_y);
    qreal tx1 = 1 - (NodeGraphicsItem::radius / 2.) / length_x;
    qreal ty1 = 1 - (NodeGraphicsItem::radius / 2.) / length_y;

    QPointF centerPos = QPoint(
            static_cast<int>((p + r) / 2),
            static_cast<int>((q + s) / 2));

    QLineF centerLine(startItem->pos(), endItem->pos());
    setLine(centerLine);

    QPointF arcPoint((1 - tx1) * p + tx1 * r, (1 - tx1) * q + tx1 * s);
    double angle = std::atan2(line().dy(), -line().dx());
    if (std::abs(angle * 180 / M_PI) >= 52 && std::abs(angle * 180 / M_PI) <= 128) {
        arcPoint = QPointF(
                (1 - ty1) * p + ty1 * r,
                (1 - ty1) * q + ty1 * s);
    }

    qreal arcHeadSize = 10;
    if (!inversionAvailable()) {
        path = QGraphicsLineItem::shape();
    } else {
        qreal offset = 4;
        if (length < 350) {
            offset += ((350 - length) / 100) * 4;
            angle -= ((350 - length / 100)) * (4. / 180) * M_PI;
        }
        qreal foo = qMax(5., qMin(25., length / 3));
        if (arc().first < arc().second) {
            centerPos += QPointF(-foo, -foo);
            setLine(QLineF(line().p1(), line().p2() + QPointF(-4, -4)));
            arcPoint += QPointF(-offset, -offset);
        } else {
            centerPos += QPointF(foo, foo);
            setLine(QLineF(line().p1(), line().p2() + QPointF(4, 4)));
            arcPoint += QPointF(offset, offset);
        }

        QPainterPath path(line().p1());
        path.cubicTo(centerPos, centerPos, line().p2());
        QPainterPathStroker pathStroker;
        QPainterPath outline = pathStroker.createStroke(path);
        path = outline;
    }
    QPointF arcP1 = arcPoint + QPointF(sin(angle + M_PI / 3) * arcHeadSize,
                                       cos(angle + M_PI / 3) * arcHeadSize);
    QPointF arcP2 = arcPoint + QPointF(sin(angle + M_PI - M_PI / 3) * arcHeadSize,
                                       cos(angle + M_PI - M_PI / 3) * arcHeadSize);

    arcHead.clear();
    arcHead << arcPoint << arcP2 << arcP1;

    if (isSelected())
        color = onSelectedColor();
    else
        color = defaultColor();

    QPen myPen = pen();
    myPen.setColor(color);
    myPen.setWidth(4);
    painter->setBrush(color);
    painter->setPen(myPen);
    painter->drawPolygon(arcHead);
    painter->drawPath(path);

    QString weight = QString::number(this->weight());
    QFont font = painter->font();
    font.setPointSize(14);
    painter->setFont(font);
    painter->drawText(centerPos + ((arc().first < arc().second) ? QPointF(-4, -4) : QPointF(4, 4)), weight);
}

void ArcGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsItem::hoverEnterEvent(event);
    setCursor(Qt::PointingHandCursor);
}

