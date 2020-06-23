#include "graphgraphicsscene.h"
#include <QDebug>
#include <memory>
#include <utility>
//#include <QRandomGenerator>
GraphGraphicsScene::GraphGraphicsScene() = default;

GraphGraphicsScene::GraphGraphicsScene(Graph *graph)
{
    setGraph(graph);
}

Graph* GraphGraphicsScene::graph() const
{
    return this->myGraph;
}

void GraphGraphicsScene::setGraph(Graph *graph)
{
    this->myGraph = graph;
    reloadData();
}

void GraphGraphicsScene::reloadData() {

    NodeGraphicsItem::radius = 50;
    this->clear();

    this->nodeItems = std::vector<NodeGraphicsItem*>(myGraph->getNodeNum());    
    std::vector<std::pair<int, int>> arcList = myGraph->getArcList();
    this->arcItems = std::vector<ArcGraphicsItem*>(arcList.size());

    for (int i = 0; i < myGraph->getNodeNum(); i++) {
        nodeItems[i] = new NodeGraphicsItem(this, myGraph->getNode(i));
    }
    for (int i = 0; i < (int)arcList.size(); i++) {
        arcItems[i] = new ArcGraphicsItem(this,
                                          nodeItems[arcList[i].first],
                                          nodeItems[arcList[i].second]);
        this->addItem(arcItems[i]);
    }
    for (int i = 0; i < myGraph->getNodeNum(); i++)
        this->addItem(nodeItems[i]);
    this->update();
}

void GraphGraphicsScene::demoAlgorithm(std::list<std::pair<int, int> > listOfPair, GraphDemoFlag flag)
{
    resetAfterDemoAlgo();
    this->listOfPair = std::move(listOfPair);
    unique_timer = std::make_unique<QTimer>();
    connect(unique_timer.get(), &QTimer::timeout, this, [this, flag]() {
        if (!this->listOfPair.empty()) {
            std::pair<int, int> pii = this->listOfPair.front();
            int arcId = this->getArcId(pii.first, pii.second);

            if (flag == GraphDemoFlag::ArcAndNode) {
                if (pii.first > -1)
                    this->nodeItems[pii.first]->setSelected(true);
                if (arcId > -1)
                    this->arcItems[arcId]->setSelected(true);
                if (pii.second > -1)
                    this->nodeItems[pii.second]->setSelected(true);
            }
            else if (flag == GraphDemoFlag::OnlyArc) {
                if (arcId > -1)
                    this->arcItems[arcId]->setSelected(true);
            }
            else if (flag == GraphDemoFlag::OnlyNode) {
                if (pii.first > -1)
                    this->nodeItems[pii.first]->setSelected(true);
                if (pii.second > -1)
                    this->nodeItems[pii.second]->setSelected(true);
            }
            this->update();
            this->listOfPair.pop_front();
        }
        else {
            unique_timer->stop();
        }
    });
    unique_timer->start(500);
}

void GraphGraphicsScene::demoAlgorithm(std::list<int> listOfNum, GraphDemoFlag flag)
{
    resetAfterDemoAlgo();
    this->listOfNum = listOfNum;
    unique_timer = std::make_unique<QTimer>();

    if (flag != GraphDemoFlag::Coloring) {
        connect(unique_timer.get(), &QTimer::timeout, this, [this, flag]() {
            if (!this->listOfNum.empty()) {
                int fromId = this->listOfNum.front();
                this->listOfNum.pop_front();
                int toId = !this->listOfNum.empty()? this->listOfNum.front() : -1;
                int arcId = this->getArcId(fromId, toId);
                if (flag == GraphDemoFlag::ArcAndNode) {
                    if (fromId > -1)
                        this->nodeItems[fromId]->setSelected(true);
                    if (arcId > -1)
                        this->arcItems[arcId]->setSelected(true);
                    if (toId > -1)
                        this->nodeItems[toId]->setSelected(true);
                }
                else if (flag == GraphDemoFlag::OnlyNode) {
                    if (fromId > -1)
                        this->nodeItems[fromId]->setSelected(true);
                }
                this->update();
            }
            else {
                unique_timer->stop();
            }
        });
    }
    else {
        std::map<int, QColor> colorMap;
        for (int color_i: listOfNum)
            colorMap[color_i] = QColor(rand() % 256, rand() % 256, rand() % 256);
        const int org_size = listOfNum.size();
        connect(unique_timer.get(), &QTimer::timeout, this, [this, colorMap, org_size]() {
            if (!this->listOfNum.empty()) {
                int id = static_cast<int>(org_size - this->listOfNum.size());
                int currColor = this->listOfNum.front();
                this->listOfNum.pop_front();
                if (id > -1) {
                    auto pos = colorMap.find(currColor);
                    this->nodeItems[id]->setOnSelectedColor(pos->second);
                    this->nodeItems[id]->setSelected(true);
                }
                this->update();
            }
            else {
                unique_timer->stop();
            }
        });
    }
    unique_timer->start(500);
}

void GraphGraphicsScene::demoAlgorithm(std::list<std::list<int> > listOfList, GraphDemoFlag flag)
{
    resetAfterDemoAlgo();
    this->listOfList = listOfList;
    unique_timer = std::make_unique<QTimer>();

    if (flag == GraphDemoFlag::Component) {
        std::vector<QColor> colorTable;
        for (int i = 0; i < listOfList.size(); i++) {
            if (i < 14)
                colorTable.push_back(NodeGraphicsItem::colorTable[i+2]);
            else
                colorTable.emplace_back(rand() % 256, rand() % 256, rand() % 256);
        }
        int org_size = listOfList.size();
        connect(unique_timer.get(), &QTimer::timeout, this, [this, colorTable, org_size]() {
            if (!this->listOfList.empty()) {
                QColor currColor = colorTable[org_size - this->listOfList.size()];
                std::list<int> currList = this->listOfList.front();
                this->listOfList.pop_front();
                for (int i: currList) {
                    for (int j: currList) {
                        int arcId = getArcId(i, j);
                        if (arcId > -1) {
                            this->arcItems[arcId]->setOnSelectedColor(currColor);
                            this->arcItems[arcId]->setSelected(true);
                        }
                    }
                    if (i > -1) {
                        this->nodeItems[i]->setOnSelectedColor(currColor);
                        this->nodeItems[i]->setSelected(true);
                    }
                }
                this->update();
            }
            else {
                unique_timer->stop();
            }
        });
        unique_timer->start(500);
    }
    else if (flag == GraphDemoFlag::ArcAndNode) {
        connect(unique_timer.get(), &QTimer::timeout, this, [this]() {
            if (!this->listOfList.empty() || !this->listOfNum.empty()) {
                bool theLast;
                if (this->listOfNum.empty()) {
                    this->listOfNum = this->listOfList.front();
                    unique_timer->setInterval(300);
                    this->listOfList.pop_front();
                }
                theLast = this->listOfList.empty();

                int fromId = this->listOfNum.front();
                this->listOfNum.pop_front();
                int toId = !this->listOfNum.empty()? this->listOfNum.front() : -1;
                int arcId = this->getArcId(fromId, toId);
                if (fromId > -1 && fromId < this->nodeItems.size())
                    this->nodeItems[fromId]->setSelected(true);
                if (arcId > -1 && arcId < this->arcItems.size())
                    this->arcItems[arcId]->setSelected(true);
                if (toId > -1 && toId < this->nodeItems.size())
                    this->nodeItems[toId]->setSelected(true);

                this->update();
                if (this->listOfNum.empty() && !theLast) {
                    for (auto gi: this->selectedItems())
                        if (gi)
                            gi->setSelected(false);
                    unique_timer->setInterval(1500);
                }
            }
            else {
                unique_timer->stop();
            }
        });
        unique_timer->start(300);
    }
}

void GraphGraphicsScene::resetAfterDemoAlgo() {
    for (auto gi: selectedItems()) {
        if (gi) {
            auto ngi = dynamic_cast<NodeGraphicsItem*>(gi);
            auto agi = dynamic_cast<NodeGraphicsItem*>(gi);
            if (ngi) ngi->setOnSelectedColor(NodeGraphicsItem::defaultOnSelectedColor);
            if (agi) agi->setOnSelectedColor(NodeGraphicsItem::defaultOnSelectedColor);
            gi->setSelected(false);
        }
    }
    this->listOfList.clear();
    this->listOfNum.clear();
    this->listOfPair.clear();
}

int GraphGraphicsScene::getArcId(int u, int v)
{
    if (u < 0 || v < 0 || u > arcItems.size() - 1 || v > arcItems.size() - 1)
        return -1;
    for (int i = 0; i < arcItems.size(); i++)
        if (arcItems[i]->arc() == std::make_pair(u, v))
            return i;
    return -1;
}
