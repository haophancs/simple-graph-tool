#include "headers/GraphGraphicsView.h"
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
    if (event->delta() > 0 && _currentScale < _scaleMax) {
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

        auto *arcItem = dynamic_cast<ArcGraphicsItem *>(item);
        auto *nodeItem = dynamic_cast<NodeGraphicsItem *>(item);
        if (nodeItem) {
            auto node_name = nodeItem->node()->name();
            emit nodeSelected(node_name);
            QMenu menu;
            menu.addAction("&Delete");
            menu.addAction("&Isolate");
            menu.addAction("Re&name");
            menu.addSeparator();
            menu.addAction("&Set arc to (Select other node by mouse)");
            menu.addSeparator();
            menu.addAction("BFS from here");
            menu.addAction("DFS from here");
            menu.addAction("Find path to");
            QAction *act = menu.exec(event->globalPos());
            if (act != nullptr) {
                if (act->text() == "&Delete")
                        emit nodeRemoved(node_name);
                if (act->text() == "&Isolate")
                        emit nodeIsolated(node_name);
                if (act->text() == "Re&name")
                        emit nodeEdited(node_name);
                if (act->text().contains("&Set arc to")) {
                    _selectTargetNode = true;
                    this->_startItem = nodeItem;
                }
                if (act->text().contains("BFS"))
                        emit startAlgorithm("BFS", node_name);
                if (act->text().contains("DFS"))
                        emit startAlgorithm("DFS", node_name);
                if (act->text().contains("Find path"))
                        emit startAlgorithm("Find path", node_name);
            } else {
                item->setSelected(false);
            }
        } else if (arcItem) {
            QMenu menu;
            menu.addAction("&Delete");
            menu.addAction("Adjust &weight");
            emit arcSelected(arcItem->arc().first, arcItem->arc().second);
            QAction *act = menu.exec(event->globalPos());
            if (act != nullptr) {
                if (act->text() == "&Delete")
                        emit arcRemoved(arcItem->arc().first, arcItem->arc().second);
                if (act->text() == "Adjust &weight")
                        emit arcSet(arcItem->arc().first, arcItem->arc().second);
            }
        }
    } else {
        if (!scene()->selectedItems().empty())
            scene()->selectedItems()[0]->setSelected(false);
        QMenu menu;
        menu.addAction("New &node");
        //menu.addAction("&Refresh");
        QAction *act = menu.exec(event->globalPos());
        if (act) {
            if (act->text() == "New &node")
                    emit nodeAdded(mapToScene(event->pos()));
            //else if (act->text() == "&Refresh") {
            //    dynamic_cast<GraphGraphicsScene*>(scene())->reload();
            //    redraw();
            //}
        }
    }
}

void GraphGraphicsView::mousePressEvent(QMouseEvent *event) {
    for (auto si: scene()->selectedItems()) {
        auto ni = dynamic_cast<NodeGraphicsItem *>(si);
        if (ni) ni->setOnSelectedColor(NodeGraphicsItem::defaultOnSelectedColor());
        else {
            auto ai = dynamic_cast<ArcGraphicsItem *>(si);
            if (ai) ai->setOnSelectedColor(ArcGraphicsItem::defaultOnSelectedColor());
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
                emit arcSet(_startItem->node()->name(), castedItemTo->node()->name());
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
        auto fai = dynamic_cast<ArcGraphicsItem *>(scene()->selectedItems()[0]);
        if (fai) emit arcSelected(fai->arc().first, fai->arc().second);
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


