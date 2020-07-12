#include "graphics/headers/GraphGraphicsScene.h"
#include "utils/random.h"
#include <QDebug>
#include <memory>
#include <utility>

GraphGraphicsScene::GraphGraphicsScene() = default;

GraphGraphicsScene::GraphGraphicsScene(GraphType::Graph *graph) {
    setGraph(graph);
}

GraphType::Graph *GraphGraphicsScene::graph() const {
    return this->_graph;
}

void GraphGraphicsScene::setGraph(GraphType::Graph *graph) {
    this->_graph = graph;
    reload();
}

void GraphGraphicsScene::reload() {
    this->clearAll();
    for (const auto &node: graph()->nodeList())
        _nodeItems[node->name()] = new NodeGraphicsItem(this, node);
    for (auto it = graph()->edgeSet().begin(); it != graph()->edgeSet().end(); ++it) {
        auto edge = GraphType::Edge(it);
        _edgeItems.insert({std::make_pair(edge.u()->name(), edge.v()->name()),
                           new EdgeGraphicsItem(this,
                                                _nodeItems[edge.u()->name()],
                                                _nodeItems[edge.v()->name()])
                          });
    }
    for (const auto &item: _edgeItems)
        this->addItem(item.second);
    for (const auto &item: _nodeItems)
        this->addItem(item.second);
    this->update();
}

void GraphGraphicsScene::demoAlgorithm(const std::list<std::pair<std::string, std::string>> &listOfPairToDemo,
                                       GraphDemoFlag flag) {
    resetAfterDemoAlgo();
    _listOfPair = listOfPairToDemo;
    _uniqueTimer = std::make_unique<QTimer>();
    if (flag == GraphDemoFlag::Coloring) {
        std::map<std::string, QColor> colorMap;
        std::set<std::string> colorCodes;
        auto random = Random();
        for (auto &it: _listOfPair)
            colorCodes.insert(it.second);
        for (auto &code: colorCodes)
            colorMap[code] = QColor(random.drawNumber(0, 255), random.drawNumber(0, 255), random.drawNumber(0, 255));
        connect(_uniqueTimer.get(), &QTimer::timeout, this, [this, colorMap]() {
            if (!this->_listOfPair.empty()) {
                auto nodeItem = this->nodeItem(this->_listOfPair.front().first);
                auto color_code = this->_listOfPair.front().second;
                this->_listOfPair.pop_front();
                if (nodeItem != nullptr) {
                    auto color = colorMap.find(color_code)->second;
                    nodeItem->setOnSelectedColor(color);
                    nodeItem->setSelected(true);
                }
                this->update();
            } else {
                _uniqueTimer->stop();
                this->_listOfPair.clear();
            }
        });
    } else {
        connect(_uniqueTimer.get(), &QTimer::timeout, this, [this, flag]() {
            if (!this->_listOfPair.empty()) {
                auto startItem = this->nodeItem(this->_listOfPair.front().first);
                auto endItem = this->nodeItem(this->_listOfPair.front().second);
                auto edgeItem = this->edgeItem(this->_listOfPair.front().first, this->_listOfPair.front().second);

                if (flag == GraphDemoFlag::EdgeAndNode) {
                    if (startItem != nullptr)
                        startItem->setSelected(true);
                    if (edgeItem != nullptr)
                        edgeItem->setSelected(true);
                    if (endItem != nullptr)
                        endItem->setSelected(true);
                } else if (flag == GraphDemoFlag::OnlyEdge) {
                    if (edgeItem != nullptr)
                        edgeItem->setSelected(true);
                } else if (flag == GraphDemoFlag::OnlyNode) {
                    if (startItem != nullptr)
                        startItem->setSelected(true);
                    if (endItem != nullptr)
                        endItem->setSelected(true);
                }
                this->update();
                this->_listOfPair.pop_front();
            } else {
                _uniqueTimer->stop();
                this->_listOfPair.clear();
            }
        });
    }
    _uniqueTimer->start(_interval);
}

void GraphGraphicsScene::demoAlgorithm(const std::list<std::string> &listOfNodeToDemo, GraphDemoFlag flag) {
    resetAfterDemoAlgo();
    this->_listOfNode = listOfNodeToDemo;
    _uniqueTimer = std::make_unique<QTimer>();
    connect(_uniqueTimer.get(), &QTimer::timeout, this, [this, flag]() {
        if (!this->_listOfNode.empty()) {
            auto start_name = this->_listOfNode.front();
            this->_listOfNode.pop_front();
            auto end_name = !this->_listOfNode.empty() ? this->_listOfNode.front() : "";

            auto startItem = this->nodeItem(start_name);
            auto endItem = this->nodeItem(end_name);
            auto edgeItem = this->edgeItem(start_name, end_name);
            if (flag == GraphDemoFlag::EdgeAndNode) {
                if (startItem != nullptr)
                    startItem->setSelected(true);
                if (edgeItem != nullptr)
                    edgeItem->setSelected(true);
                if (endItem != nullptr)
                    endItem->setSelected(true);
            } else if (flag == GraphDemoFlag::OnlyNode) {
                if (startItem != nullptr)
                    startItem->setSelected(true);
            }
            this->update();
        } else {
            this->_uniqueTimer->stop();
            this->_listOfNode.clear();
        }
    });
    _uniqueTimer->start(_interval);
}

void GraphGraphicsScene::demoAlgorithm(const std::list<std::list<std::string> > &listOfListToDemo, GraphDemoFlag flag) {
    resetAfterDemoAlgo();
    this->_listOfList = listOfListToDemo;
    _uniqueTimer = std::make_unique<QTimer>();

    if (flag == GraphDemoFlag::Component) {
        std::vector<QColor> colorTable;
        for (int i = 0; i < this->_listOfList.size(); ++i) {
            auto random = Random();
            colorTable.emplace_back(QColor(random.drawNumber(0, 255), random.drawNumber(0, 255),
                                           random.drawNumber(0, 255)));
        }
        int org_size = this->_listOfList.size();
        connect(_uniqueTimer.get(), &QTimer::timeout, this, [this, colorTable, org_size]() {
            if (!this->_listOfList.empty()) {
                QColor currColor = colorTable[org_size - this->_listOfList.size()];
                std::list<std::string> currList = this->_listOfList.front();
                this->_listOfList.pop_front();
                for (const auto &start_name: currList) {
                    for (const auto &end_name: currList) {
                        if (start_name != end_name) {
                            auto edgeItem = this->edgeItem(start_name, end_name);
                            if (edgeItem != nullptr) {
                                edgeItem->setOnSelectedColor(currColor);
                                edgeItem->setSelected(true);
                            }
                        }
                    }
                    auto startItem = this->nodeItem(start_name);
                    if (startItem != nullptr) {
                        startItem->setOnSelectedColor(currColor);
                        startItem->setSelected(true);
                    }
                }
                this->update();
            } else {
                _uniqueTimer->stop();
                this->_listOfList.clear();
            }
        });
        _uniqueTimer->start(_interval);
    } else if (flag == GraphDemoFlag::EdgeAndNode) {
        connect(_uniqueTimer.get(), &QTimer::timeout, this, [this]() {
            if (!this->_listOfList.empty() || !this->_listOfNode.empty()) {
                bool theLast;
                if (this->_listOfNode.empty()) {
                    this->_listOfNode = this->_listOfList.front();
                    this->_listOfList.pop_front();
                }
                theLast = this->_listOfList.empty();

                auto start_name = this->_listOfNode.front();
                this->_listOfNode.pop_front();
                auto end_name = !this->_listOfNode.empty() ? this->_listOfNode.front() : "";
                auto startItem = this->nodeItem(start_name);
                auto endItem = this->nodeItem(end_name);
                auto edgeItem = this->edgeItem(start_name, end_name);
                if (startItem != nullptr)
                    startItem->setSelected(true);
                if (endItem != nullptr)
                    endItem->setSelected(true);
                if (edgeItem != nullptr)
                    edgeItem->setSelected(true);

                this->update();
                if (this->_listOfNode.empty() && !theLast) {
                    for (auto gi: this->selectedItems())
                        if (gi != nullptr)
                            gi->setSelected(false);
                }
            } else {
                _uniqueTimer->stop();
            }
        });
        _uniqueTimer->start(_interval);
    }
}

void GraphGraphicsScene::resetAfterDemoAlgo() {
    for (auto gi: selectedItems()) {
        if (gi) {
            auto ngi = dynamic_cast<NodeGraphicsItem *>(gi);
            auto agi = dynamic_cast<EdgeGraphicsItem *>(gi);
            if (ngi) ngi->setOnSelectedColor(NodeGraphicsItem::defaultOnSelectedColor());
            if (agi) agi->setOnSelectedColor(EdgeGraphicsItem::defaultOnSelectedColor());
            gi->setSelected(false);
        }
    }
    this->_listOfList.clear();
    this->_listOfNode.clear();
    this->_listOfPair.clear();
}

EdgeGraphicsItem *GraphGraphicsScene::edgeItem(const std::string &uname, const std::string &vname) {
    if (_edgeItems.find(std::make_pair(uname, vname)) != _edgeItems.end())
        return _edgeItems.find(std::make_pair(uname, vname))->second;
    else if (_graph->isUndirected() && _edgeItems.find(std::make_pair(vname, uname)) != _edgeItems.end())
        return _edgeItems.find(std::make_pair(vname, uname))->second;
    return nullptr;
}

NodeGraphicsItem *GraphGraphicsScene::nodeItem(const std::string &name) {
    if (_nodeItems.find(name) != _nodeItems.end())
        return _nodeItems[name];
    return nullptr;
}

void GraphGraphicsScene::clearAll() {
    this->clear();
    this->_nodeItems.clear();
    this->_edgeItems.clear();
}

GraphGraphicsScene::~GraphGraphicsScene() {
    this->clearAll();
}

