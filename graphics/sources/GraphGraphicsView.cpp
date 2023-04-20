#include "graphics/headers/GraphGraphicsView.h"
#include <QDebug>

GraphGraphicsView::GraphGraphicsView() {
    setDragMode(ScrollHandDrag);
    _moving = false;
    _selectTargetNode = false;
    _isRunningAlgoDemo = false;
    _currentScale = 1.;
}

void GraphGraphicsView::wheelEvent(QWheelEvent *event) {
    QGraphicsView::wheelEvent(event);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.05;
    if (event->delta() > 0 && _currentScale <= _scaleMax) {
        scale(scaleFactor, scaleFactor);
        _currentScale *= scaleFactor;
    } else {
        scale(1 / scaleFactor, 1 / scaleFactor);
        _currentScale /= scaleFactor;
    }
}

void GraphGraphicsView::contextMenuEvent(QContextMenuEvent *event) {
    for (auto gi: scene()->selectedItems())
        gi->setSelected(false);

    QList<QGraphicsItem *> clickedItems = items(event->pos());
    if (!clickedItems.empty()) {
        auto item = clickedItems[0];
        item->setSelected(true);

        auto *edgeItem = dynamic_cast<EdgeGraphicsItem *>(item);
        auto *nodeItem = dynamic_cast<NodeGraphicsItem *>(item);
        if (nodeItem) {
            auto node_name = nodeItem->node()->name();
            emit nodeSelected(node_name);
            QMenu menu;
            menu.addAction("&Set edge");
            menu.addSeparator();
            menu.addAction("&Delete");
            menu.addAction("&Isolate");
            menu.addAction("Re&name");
            menu.addSeparator();
            menu.addAction("BFS from here");
            menu.addAction("DFS from here");
            menu.addSeparator();
            menu.addAction("Dijkstra");
            menu.addAction("A-star");
            menu.addSeparator();
            menu.addAction("MST by Prim");
            menu.addAction("ST by BFS");
            menu.addAction("ST by DFS");
            QAction *act = menu.exec(event->globalPos());
            if (act != nullptr) {
                if (act->text() == "Re&name")
                    emit nodeEdited(node_name);
                if (act->text() == "&Isolate")
                    emit nodeIsolated(node_name);
                if (act->text() == "&Delete")
                    emit nodeRemoved(node_name);
                if (act->text().contains("&Set edge to")) {
                    this->_selectTargetNode = true;
                    this->_startItem = nodeItem;
                }
                if (act->text().contains("BFS"))
                    emit startAlgorithm(StartAlgoFlag::BFS, node_name);
                if (act->text().contains("DFS"))
                    emit startAlgorithm(StartAlgoFlag::DFS, node_name);
                if (act->text().contains("Dijkstra"))
                    emit startAlgorithm(StartAlgoFlag::Dijkstra, node_name);
                if (act->text().contains("A-star"))
                    emit startAlgorithm(StartAlgoFlag::AStar, node_name);
                if (act->text().contains("Prim"))
                    emit startAlgorithm(StartAlgoFlag::Prim, node_name);
                if (act->text().contains("ST by DFS"))
                    emit startAlgorithm(StartAlgoFlag::ST_DFS, node_name);
                if (act->text().contains("ST by BFS"))
                    emit startAlgorithm(StartAlgoFlag::ST_BFS, node_name);
            } else {
                item->setSelected(false);
            }
        } else if (edgeItem) {
            QMenu menu;
            menu.addAction("&Delete");
            if (dynamic_cast<GraphGraphicsScene *>(scene())->graph()->isWeighted())
                menu.addAction("Adjust &weight");
            emit edgeSelected(edgeItem->edge().u()->name(), edgeItem->edge().v()->name());
            QAction *act = menu.exec(event->globalPos());
            if (act != nullptr) {
                if (act->text() == "&Delete")
                   emit edgeRemoved(edgeItem->edge().u()->name(), edgeItem->edge().v()->name());
                if (act->text() == "Adjust &weight")
                   emit edgeSet(edgeItem->edge().u()->name(), edgeItem->edge().v()->name());
            }
        }
    } else {
        if (!scene()->selectedItems().empty())
            scene()->selectedItems()[0]->setSelected(false);
        QMenu menu;
        menu.addAction("Create node now");
        menu.addAction("Create node...");
        QAction *act = menu.exec(event->globalPos());
        if (act) {
            if (act->text() == "Create node...")
               emit nodeAdded(mapToScene(event->pos()), false);
            else if (act->text() == "Create node now")
               emit nodeAdded(mapToScene(event->pos()), true);
        }
    }
}

void GraphGraphicsView::mousePressEvent(QMouseEvent *event) {
    for (auto si: scene()->selectedItems()) {
        auto ni = dynamic_cast<NodeGraphicsItem *>(si);
        if (ni) ni->setOnSelectedColor(NodeGraphicsItem::defaultOnSelectedColor());
        else {
            auto ai = dynamic_cast<EdgeGraphicsItem *>(si);
            if (ai) ai->setOnSelectedColor(EdgeGraphicsItem::defaultOnSelectedColor());
        }
    }

    auto graphScene = dynamic_cast<GraphGraphicsScene *>(scene());
    if (graphScene->_uniqueTimer) {
        graphScene->_uniqueTimer->stop();
    }
    graphScene->resetAfterDemoAlgo();

    if (!_selectTargetNode)
        QGraphicsView::mousePressEvent(event);
    if (_selectTargetNode) {
        QList<QGraphicsItem *> itemsTo = items(event->pos());
        if (!itemsTo.empty()) {
            auto *castedItemTo = dynamic_cast<NodeGraphicsItem *>(itemsTo[0]);
            if (_startItem && castedItemTo && _startItem != castedItemTo) {
                castedItemTo->setSelected(false);
                emit edgeSet(_startItem->node()->name(), castedItemTo->node()->name());
            }
        }
    }
    _selectTargetNode = false;
    this->_startItem = nullptr;
    scene()->update();
    viewport()->update();
}

void GraphGraphicsView::mouseReleaseEvent(QMouseEvent *event) {
    if (!scene()->selectedItems().empty()) {
        auto fni = dynamic_cast<NodeGraphicsItem *>(scene()->selectedItems()[0]);
        auto fai = dynamic_cast<EdgeGraphicsItem *>(scene()->selectedItems()[0]);
        if (fai) emit edgeSelected(fai->edge().u()->name(), fai->edge().v()->name());
        else if (fni) emit nodeSelected(fni->node()->name());
    }
    if (items(event->pos()).empty())
            emit unSelected();
    QGraphicsView::mouseReleaseEvent(event);
}

void GraphGraphicsView::setScene(GraphGraphicsScene *scene) {
    connect(scene, SIGNAL(graphChanged()), this, SLOT(redraw()));
    connect(scene, SIGNAL(needRedraw()), this, SLOT(redraw()));
    QGraphicsView::setScene(scene);
}

void GraphGraphicsView::redraw() {
    this->viewport()->update();
}


