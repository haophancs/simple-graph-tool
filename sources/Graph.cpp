#include "headers/Graph.h"
#include <cmath>
#include <iomanip>
#include <QDebug>
#include <algorithm>
#include "headers/NodeGraphicsItem.h"

Graph::Graph() = default;

Graph::Graph(int node_num) {
    init(node_num);
}

void Graph::clear() {
    this->nodeList.clear();
    this->adjMatrix.clear();
}

void Graph::readFromFile(const std::string &file) {
    clear();
    std::ifstream in(file);
    if (!in) throw "file not existed";

    int n;
    in >> n;
    if (n <= 0) throw "n <= 0";
    std::string w, name;

    for (int i = 0; i < n; i++) {

        if (in.eof()) throw "eof";
        in >> name, addNode(Node(name, i));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (in.eof()) throw "eof";
            in >> w;
            if (w != "INF")
                setArc(i, j, std::stoi(w));
        }
    }
    for (int i = 0; i < n; i++) {

        if (in.eof()) throw "eof";
        qreal x;
        in >> x;
        if (in.eof()) throw "eof";
        qreal y;
        in >> y;
        nodeList[i].setEuclidePos(QPointF(x, y));
    }
    in.close();
}

void Graph::writeToFile(const std::string &file) const {

    std::ofstream out(file);
    out << getNodeNum() << "\n";
    for (int i = 0; i < getNodeNum(); i++)
        out << nodeList[i].getName() << "\n";

    int max_length = 0;
    for (int i = 0; i < getNodeNum(); i++) {
        for (int j = 0; j < getNodeNum(); j++) {
            if (adjMatrix[i][j] != INT_MAX)
                max_length = std::max(max_length, (int) std::to_string(adjMatrix[i][j]).length());
            else
                max_length = std::max(max_length, 3);
        }
    }

    for (int i = 0; i < getNodeNum(); i++) {
        for (int j = 0; j < getNodeNum(); j++) {
            if (hasThisArc(i, j))
                out << std::left << std::setw(max_length) << adjMatrix[i][j] << " ";
            else
                out << std::left << std::setw(max_length) << "INF" << " ";
        }
        out << "\n";
    }
    for (int i = 0; i < getNodeNum(); i++)
        out << nodeList[i].getEuclidePos().rx() << " " << nodeList[i].getEuclidePos().ry() << "\n";
    out.close();
}

void Graph::init(int node_num) {
    if (node_num <= 0) return;
    if (node_num > 26) {
        std::cout << "Maximum number of automatically generated nodes is 26\n";
        return;
    }
    this->clear();
    this->adjMatrix = std::vector<std::vector<int>>(node_num, std::vector<int>(node_num, INT_MAX));
    for (int i = 0; i < node_num; i++) {
        this->nodeList.emplace_back(std::string(1, 'a' + i), i);
        this->adjMatrix[i][i] = 0;
        QPointF point((1 - sin((i * 6.28) / node_num)) * node_num * NodeGraphicsItem::radius / 2.,
                      (1 - cos((i * 6.28) / node_num)) * node_num * NodeGraphicsItem::radius / 2.);
        this->nodeList[i].setEuclidePos(point);
    }
}

Graph Graph::getTranspose() const {

    Graph graph(getNodeNum());
    for (int u = 0; u < getNodeNum(); u++)
        for (int v = 0; v < getNodeNum(); v++)
            if (adjMatrix[u][v] != INT_MAX)
                graph.setArc(u, v, adjMatrix[u][v]);
    return graph;
}

void Graph::printAdjMatrix() const {

    int max_length = 0;
    for (int i = 0; i < getNodeNum(); i++) {
        for (int j = 0; j < getNodeNum(); j++) {
            if (adjMatrix[i][j] != INT_MAX)
                max_length = std::max(max_length, (int) std::to_string(adjMatrix[i][j]).length());
            else
                max_length = std::max(max_length, 3);
        }
    }
    for (int i = 0; i < getNodeNum(); i++)
        max_length = std::max(max_length, (int) nodeList[i].getName().length());

    std::cout << std::left << std::setw(max_length) << " " << " ";
    for (int i = 0; i < getNodeNum(); i++)
        std::cout << std::left << std::setw(max_length) << nodeList[i].getName() << " ";
    std::cout << "\n";

    for (int i = 0; i < getNodeNum(); i++) {
        std::cout << std::left << std::setw(max_length) << nodeList[i].getName() << " ";
        for (int j = 0; j < getNodeNum(); j++) {
            if (adjMatrix[i][j] != INT_MAX)
                std::cout << std::left << std::setw(max_length) << adjMatrix[i][j] << " ";
            else
                std::cout << std::left << std::setw(max_length) << "INF" << " ";
        }
        std::cout << std::endl;
    }
}

int Graph::findNodeIdByName(const std::string &name) const {
    for (int i = 0; i < getNodeNum(); i++)
        if (nodeList[i].getName() == name)
            return i;
    return -1;
}

bool Graph::setArc(int u, int v, int w) {
    if (u == v) return true;
    if (hasThisArc(u, v)) {
        this->adjMatrix[u][v] = w;
        return true;
    }
    if (hasThisNode(u) && hasThisNode(v)) {
        if (w == INT_MAX || w == 0) {
            removeArc(u, v);
            return true;
        }
        this->adjMatrix[u][v] = w;
        this->nodeList[u].incNegativeDeg();
        this->nodeList[v].incPositiveDeg();

        return true;
    }
    return false;
}

bool Graph::removeArc(int u, int v) {
    if (u == v) return true;

    if (hasThisNode(u) && hasThisNode(v) && hasThisArc(u, v)) {
        this->adjMatrix[u][v] = INT_MAX;
        this->nodeList[u].decNegativeDeg();
        this->nodeList[v].decPositiveDeg();
        return true;
    }
    return false;
}

bool Graph::addNode(Node node) {
    if (hasThisNode(node.getName())) return false;

    node.setId(getNodeNum());
    this->nodeList.push_back(node);
    std::vector<int> new_row(getNodeNum(), INT_MAX);
    new_row[getNodeNum() - 1] = 0;
    adjMatrix.push_back(new_row);
    for (int i = 0; i < getNodeNum(); i++)
        adjMatrix[i].push_back(INT_MAX);

    /*std::vector<std::pair<int, Node>> list(getNodeNum());
    for (int i = 0; i < list.size(); i++)
        list[i] = std::make_pair(i, nodeList[i]);
    std::sort(list.begin(), list.end(), [](const std::pair<int, Node> &a, const std::pair<int, Node> &b) {
        return a.second.getName() < b.second.getName();
    });
    std::vector<int> idlist(getNodeNum());
    for (int i = 0; i < list.size(); i++) idlist[i] = list[i].first;
    std::vector<Node> new_nodelist;
    std::vector<std::vector<int>> new_mat;
    for (int i = 0; i < idlist.size(); i++) {
        std::vector<int> new_row;
        for (int j = 0; j < idlist.size(); j++)
            new_row.push_back(adjMatrix[i][idlist[j]]);
        new_mat.push_back(new_row);
        new_nodelist.push_back(nodeList[idlist[i]]);
        new_nodelist[i].setId(i);
    }
    this->adjMatrix = new_mat;
    this->nodeList = new_nodelist;*/
    return true;
}

bool Graph::removeNode(int id) {
    for (int v = 0; v < getNodeNum(); v++) {
        removeArc(v, id);
        removeArc(id, v);
    }
    if (!hasThisNode(id)) return false;
    this->nodeList.erase(this->nodeList.begin() + id);
    this->adjMatrix.erase(this->adjMatrix.begin() + id);
    for (int i = 0; i < getNodeNum(); i++) {
        adjMatrix[i].erase(adjMatrix[i].begin() + id);
        nodeList[i].setId(i);
    }
    return true;
}

bool Graph::isolateNode(int id) {
    if (!hasThisNode(id)) return false;
    for (int v = 0; v < getNodeNum(); v++) {
        removeArc(v, id);
        removeArc(id, v);
    }
    this->adjMatrix[id] = std::vector<int>(getNodeNum(), INT_MAX);
    for (int i = 0; i < getNodeNum(); i++)
        adjMatrix[i][id] = INT_MAX;
    this->adjMatrix[id][id] = 0;
    return true;
}

std::vector<std::pair<int, int>> Graph::getArcList() const {
    std::vector<std::pair<int, int>> res;
    for (int u = 0; u < getNodeNum(); u++)
        for (int v = 0; v < getNodeNum(); v++)
            if (hasThisArc(u, v))
                res.emplace_back(u, v);
    return res;
}

const Node *Graph::getNode(int id) {
    if (!hasThisNode(id))
        return nullptr;
    return &nodeList[id];
}

int Graph::getArcWeight(int u, int v) const {
    if (u == v)
        return 0;
    if (hasThisArc(u, v))
        return this->adjMatrix[u][v];
    else
        return INT_MAX;
}

void Graph::setNodeName(int id, std::string newName) {
    if (!hasThisNode(id)) return;
    this->nodeList[id].setName(newName);
}

void Graph::setNodeName(std::string oldName, std::string newName) {
    setNodeName(findNodeIdByName(oldName), newName);
}
