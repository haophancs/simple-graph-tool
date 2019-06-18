#include "graph.h"
#include <math.h>
#include <iomanip>
#include <QDebug>
#include <algorithm>
#include "nodegraphicsitem.h"

Graph::Graph() {
}

Graph::Graph(int node_num) {
    init(node_num);
}

void Graph::clear() {
    this->node_list.clear();
    this->adj_mat.clear();
}

void Graph::readFromFile(std::string file) {
    clear();
    std::ifstream in(file);
    if (!in) throw "file not existed";

    int n; in >> n;
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
        qreal x; in >> x;
        if (in.eof()) throw "eof";
        qreal y; in >> y;
        node_list[i].setEuclidePos(QPointF(x, y));
    }
    in.close();
}

void Graph::writeToFile(std::string file) {

    std::ofstream out(file);
    out << getNodeNum() << "\n";
    for (int i = 0; i < getNodeNum(); i++)
        out << node_list[i].getName() << "\n";

    int max_length = 0;
    for (int i = 0; i < getNodeNum(); i++) {
        for (int j = 0; j < getNodeNum(); j++) {
            if (adj_mat[i][j] != INT_MAX)
                max_length = std::max(max_length, (int)std::to_string(adj_mat[i][j]).length());
            else
                max_length = std::max(max_length, 3);
        }
    }

    for (int i = 0; i < getNodeNum(); i++) {
        for (int j = 0; j < getNodeNum(); j++) {
            if (hasThisArc(i, j))
                out << std::left << std::setw(max_length) << adj_mat[i][j] << " ";
            else
                out << std::left << std::setw(max_length) << "INF" << " ";
        }
        out << "\n";
    }
    for (int i = 0; i < getNodeNum(); i++)
        out << node_list[i].getEuclidePos().rx() << " " << node_list[i].getEuclidePos().ry() << "\n";
    out.close();
}

void Graph::init(int node_num) {
    if (node_num <= 0) return;
    if (node_num > 26) {
        std::cout << "Maximum number of automatically gererated nodes is 26\n";
        return;
    }
    this->clear();
    this->adj_mat = std::vector<std::vector<int>>(node_num, std::vector<int>(node_num, INT_MAX));
    for (int i = 0; i < node_num; i++) {
        this->node_list.push_back(Node(std::string(1, 'a' + i), i));
        this->adj_mat[i][i] = 0;
        QPointF point((1 - sin((i * 6.28) / node_num)) * node_num*NodeGraphicsItem::radius/2.,
                      (1 - cos((i * 6.28) / node_num)) * node_num*NodeGraphicsItem::radius/2.);
        this->node_list[i].setEuclidePos(point);
    }
}

Graph Graph::getTranpose() {

    Graph graph(getNodeNum());
    for (int u = 0; u < getNodeNum(); u++)
        for (int v = 0; v < getNodeNum(); v++)
            if (adj_mat[u][v] != INT_MAX)
                graph.setArc(v, u, adj_mat[u][v]);
    return graph;
}
void Graph::printAdjMat() const {

    int max_length = 0;
    for (int i = 0; i < getNodeNum(); i++) {
        for (int j = 0; j < getNodeNum(); j++) {
            if (adj_mat[i][j] != INT_MAX)
                max_length = std::max(max_length, (int)std::to_string(adj_mat[i][j]).length());
            else
                max_length = std::max(max_length, 3);
        }
    }
    for (int i = 0; i < getNodeNum(); i++)
        max_length = std::max(max_length, (int)node_list[i].getName().length());

    std::cout << std::left << std::setw(max_length) << " " << " ";
    for (int i = 0; i < getNodeNum(); i++)
        std::cout << std::left << std::setw(max_length) << node_list[i].getName() << " ";
    std::cout << "\n";

    for (int i = 0; i < getNodeNum(); i++) {
        std::cout << std::left << std::setw(max_length) << node_list[i].getName() << " ";
        for (int j = 0; j < getNodeNum(); j++) {
            if (adj_mat[i][j] != INT_MAX)
                std::cout << std::left << std::setw(max_length) << adj_mat[i][j] << " ";
            else
                std::cout << std::left << std::setw(max_length) << "INF" << " ";
        }
        std::cout << std::endl;
    }
}

int Graph::findNodeIdByName(std::string name) const {
    for (int i = 0; i < getNodeNum(); i++)
        if (node_list[i].getName() == name)
            return i;
    return -1;
}

bool Graph::setArc(int u, int v, int w) {
    if (u == v) return true;
    if (hasThisArc(u, v)) {
        this->adj_mat[u][v] = w;
        return true;
    }
    if (hasThisNode(u) && hasThisNode(v)) {
        if (w == INT_MAX || w == 0) {
            removeArc(u, v);
            return true;
         }
        this->adj_mat[u][v] = w;
        this->node_list[u].incNegativeDeg();
        this->node_list[v].incPositiveDeg();

        return true;
    }
    return false;
}

bool Graph::removeArc(int u, int v) {
    if (u == v) return true;

    if (hasThisNode(u) && hasThisNode(v) && hasThisArc(u, v)) {
        this->adj_mat[u][v] = INT_MAX;
        this->node_list[u].decNegativeDeg();
        this->node_list[v].decPositiveDeg();
        return true;
    }
    return false;
}

bool Graph::addNode(Node node) {
    if (hasThisNode(node.getName())) return false;

    node.setId(getNodeNum());
    this->node_list.push_back(node);
    std::vector<int> new_row(getNodeNum(), INT_MAX);
    new_row[getNodeNum() - 1] = 0;
    adj_mat.push_back(new_row);
    for (int i = 0; i < getNodeNum(); i++)
        adj_mat[i].push_back(INT_MAX);

    /*std::vector<std::pair<int, Node>> list(getNodeNum());
    for (int i = 0; i < list.size(); i++)
        list[i] = std::make_pair(i, node_list[i]);
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
            new_row.push_back(adj_mat[i][idlist[j]]);
        new_mat.push_back(new_row);
        new_nodelist.push_back(node_list[idlist[i]]);
        new_nodelist[i].setId(i);
    }
    this->adj_mat = new_mat;
    this->node_list = new_nodelist;*/
    return true;
}

bool Graph::removeNode(int id) {
    for (int v = 0; v < getNodeNum(); v++)
    {
        removeArc(v, id);
        removeArc(id, v);
    }
    if (!hasThisNode(id)) return false;
    this->node_list.erase(this->node_list.begin() + id);
    this->adj_mat.erase(this->adj_mat.begin() + id);
    for (int i = 0; i < getNodeNum(); i++) {
        adj_mat[i].erase(adj_mat[i].begin() + id);
        node_list[i].setId(i);
    }
    return true;
}

bool Graph::isolateNode(int id) {
    if (!hasThisNode(id)) return false;
    for (int v = 0; v < getNodeNum(); v++)
    {
        removeArc(v, id);
        removeArc(id, v);
    }
    this->adj_mat[id] = std::vector<int>(getNodeNum(), INT_MAX);
    for (int i = 0; i < getNodeNum(); i++)
        adj_mat[i][id] = INT_MAX;
    this->adj_mat[id][id] = 0;
    return true;
}

std::vector<std::pair<int, int>> Graph::getArcList() const
{
    std::vector<std::pair<int, int>> res;
    for (int u = 0; u < getNodeNum(); u++)
        for (int v = 0; v < getNodeNum(); v++)
            if (hasThisArc(u, v))
                res.push_back(std::make_pair(u, v));
    return res;
}
