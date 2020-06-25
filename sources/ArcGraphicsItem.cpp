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
    this->startItem = startItem;
    this->endItem = endItem;
    this->myScene = scene;
    this->color = std::move(baseColor);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setAcceptHoverEvents(true);
    setPen(QPen(this->color, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    this->onSelectedColor = colorTable()[1];

    updatePosition();
    connect(startItem, SIGNAL(positionChanged()), SLOT(updatePosition()));
    connect(endItem, SIGNAL(positionChanged()), SLOT(updatePosition()));
    emit myScene->needRedraw();
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
    return this->path;
}

std::pair<int, int> ArcGraphicsItem::arc() const {
    return std::make_pair(startItem->getNode()->getId(),
                          endItem->getNode()->getId());
}

int ArcGraphicsItem::weight() const {
    return myScene->getGraph()->getArcWeight(arc().first, arc().second);
}

void ArcGraphicsItem::updatePosition() {

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

    QLineF centerLine(mapFromItem(startItem, 0, 0), mapFromItem(endItem, 0, 0));
    setLine(centerLine);
    this->path = QGraphicsLineItem::shape();

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
        this->path = outline;
    }

    QPointF arcP1 = arcHeadPoint + QPointF(sin(angle + M_PI / 3) * arcHeadSize,
                                       cos(angle + M_PI / 3) * arcHeadSize);
    QPointF arcP2 = arcHeadPoint + QPointF(sin(angle + M_PI - M_PI / 3) * arcHeadSize,
                                       cos(angle + M_PI - M_PI / 3) * arcHeadSize);

    QPolygonF arcHead;
    arcHead << arcHeadPoint << arcP2 << arcP1;
    this->path.addPolygon(arcHead);

    QFont font;
    font.setPointSize(13);
    auto textPos = centerPos;
    this->path.addText(textPos, font, QString::number(this->weight()));
    emit myScene->needRedraw();
}

void ArcGraphicsItem::setOnSelectedColor(QColor newColor) {
    this->onSelectedColor = std::move(newColor);
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
    //updatePosition();
    if (isSelected())
        color = getOnSelectedColor();
    else
        color = defaultColor();

    QPen myPen = pen();
    myPen.setColor(color);
    myPen.setWidth(4);
    painter->setBrush(color);
    painter->setPen(myPen);
    painter->drawPath(this->shape());
}

void ArcGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsItem::hoverEnterEvent(event);
    setCursor(Qt::PointingHandCursor);
}

