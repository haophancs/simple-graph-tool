#include "basis/headers/Graph.h"
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "utils/random.h"

using namespace GraphType;

Graph::Graph(int node_num, bool directed, bool weighted) :
        _directed(directed),
        _weighted(weighted),
        _invalidValue(_calcInvalid(directed, weighted)),
        _weightRange(_calcWeightRange(weighted)) {
    _init(node_num);
}

void Graph::_init(int node_num) {
    this->clear();
    if (node_num <= 0) return;
    Random random;
    for (int i = 0; i < node_num; ++i) {
        QPointF point((1 - sin((i * 6.28) / node_num)) * node_num * 80 / 2.,
                      (1 - cos((i * 6.28) / node_num)) * node_num * 80 / 2.);
        addNode(Node(nextNodeName(), point));
    }
}

Graph::Graph(const Graph &obj) :
        _directed(obj._directed),
        _weighted(obj._weighted),
        _invalidValue(obj._invalidValue),
        _weightRange(obj._weightRange) {
    this->clear();
    for (auto &node: obj.nodeList())
        this->addNode(node->name());
    for (auto it = obj.edgeSet().begin(); it != obj.edgeSet().end(); ++it) {
        this->setEdge(Edge(it).u()->name(), Edge(it).v()->name(), Edge(it).weight());
    }
}

void Graph::clear() {
    this->_nodeSet.clear();
    this->_edgeSet.clear();
    this->_cachedNodeList.clear();
}

Graph Graph::readFromFile(const std::string &file) {
    std::ifstream in(file);
    if (!in) throw "file not existed";

    bool directed, weighted;
    in >> directed >> weighted;
    Graph graph(directed, weighted);

    int countNodes;
    in >> countNodes;
    if (countNodes <= 0) throw "Number of nodes <= 0";
    std::string name;
    qreal x, y;
    for (int i = 0; i < countNodes; ++i) {
        if (in.eof()) throw "eof";
        in >> name >> x >> y, graph.addNode(Node(name, QPointF(x, y)));
    }
    int countEdges;
    in >> countEdges;
    if (countEdges > 0) {
        std::string start, end;
        int weight;
        for (int i = 0; i < countEdges; ++i) {
            if (in.eof()) throw "eof";
            in >> start >> end >> weight;
            if (weight >= graph.weightRange().first && weight <= graph.weightRange().second)
                graph.setEdge(start, end, weight);
            else
                throw "Invalid weight value";
        }
    }
    in.close();
    return graph;
}

void Graph::writeToFile(const std::string &file, const Graph &graph) {
    std::ofstream out;
    out.open(file, std::ofstream::out | std::ofstream::trunc);
    out << graph;
    out.close();
}

Node *Graph::node(const std::string &node_name) const {
    if (!hasNode(node_name))
        return nullptr;
    return const_cast<Node *>(&(*_nodeSet.find(Node(node_name))));
}

bool Graph::addNode(const Node &_node) {
    if (hasNode(_node.name())) return false;
    _nodeSet.insert(_node);
    _cachedNodeList.emplace_back(node(_node.name()));
    return true;
}

std::string Graph::nextNodeName() const {
    for (int i = 0; i < countNodes(); ++i) {
        auto name = std::string(1, 'a' + (i % 26)) + std::to_string(int(i / 26));
        if (!hasNode(name))
            return name;
    }
    return std::string(1, 'a' + (countNodes() % 26)) + std::to_string(int(countNodes() / 26));
}

bool Graph::addNode(std::string node_name) {
    if (node_name.empty())
        node_name = nextNodeName();
    return addNode(Node(node_name));
}

bool Graph::removeNode(Node *node) {
    if (!hasNode(node))
        return false;
    isolateNode(node);
    _nodeSet.erase(*node);
    _cachedNodeList.remove(node);
    return true;
}

bool Graph::removeNode(const std::string &name) {
    return removeNode(node(name));
}

bool Graph::isolateNode(Node *node) {
    if (!hasNode(node))
        return false;
    std::list<Edge> cachedEdges;
    for (auto it = edgeSet().begin(); it != edgeSet().end(); ++it) {
        if (Edge(it).u() == node || Edge(it).v() == node)
            cachedEdges.emplace_back(Edge(it));
    }
    for (auto &edge: cachedEdges)
        removeEdge(edge.u(), edge.v());
    return true;
}

bool Graph::isolateNode(const std::string &name) {
    return isolateNode(node(name));
}

bool Graph::setNodeName(Node *node, const std::string &new_name) {
    if (!hasNode(node) || hasNode(new_name) || node->name() == new_name)
        return false;
    std::list<Edge> cachedEdges;
    for (auto it = edgeSet().begin(); it != edgeSet().end(); ++it) {
        auto edge = Edge(it);
        if (edge.u() == node || edge.v() == node)
            cachedEdges.emplace_back(edge);
    }
    addNode(Node(new_name, node->euclidePos()));
    for (auto it = edgeSet().begin(); it != edgeSet().end(); ++it) {
        auto edge = Edge(it);
        if (edge.u()->name() == node->name())
            setEdge(new_name, edge.v()->name(), edge.weight());
        else if (edge.v()->name() == node->name())
            setEdge(edge.u()->name(), new_name, edge.weight());
    }
    removeNode(node);
    return true;
}

bool Graph::setNodeName(const std::string &old_name, const std::string &new_name) {
    return setNodeName(node(old_name), new_name);
}

int Graph::weight(Node *u, Node *v) const {
    if (u == v)
        return 0;
    if (!hasEdge(u, v))
        return _invalidValue;
    return edge(u, v).weight();
}

int Graph::weight(const std::string &uname, const std::string &vname) const {
    return weight(node(uname), node(vname));
}

bool Graph::setEdge(Node *u, Node *v, int w) {
    if (w == _invalidValue)
        return removeEdge(u, v);

    if (u == v || !hasNode(u) || !hasNode(v)
        || w < _weightRange.first || w > _weightRange.second)
        return false;

    if (hasDirectedEdge(u, v))
        _edgeSet.at({u, v}) = w;
    else if (!_directed && hasDirectedEdge(v, u))
        _edgeSet.at({v, u}) = w;
    else {
        _edgeSet.insert({{u, v}, w});
        if (_directed) {
            u->incNegDegree();
            v->incPosDegree();
        } else {
            u->incUndirDegree();
            v->incUndirDegree();
        }
    }
    return true;
}

bool Graph::setEdge(const std::string &uname, const std::string &vname, int w) {
    return setEdge(node(uname), node(vname), w);
}

bool Graph::setEdge(const std::string &uname, const std::string &vname) {
    return setEdge(node(uname), node(vname), 1);
}

bool Graph::removeEdge(Node *u, Node *v) {
    if (u == v || !hasNode(u) || !hasNode(v))
        return false;
    if (hasDirectedEdge(u, v)) {
        _edgeSet.erase({u, v});
        if (_directed) {
            u->decNegDegree();
            v->decPosDegree();
        } else {
            u->decUndirDegree();
            v->decUndirDegree();
        }
        return true;
    } else if (!_directed && hasDirectedEdge(v, u)) {
        _edgeSet.erase({v, u});
        u->decUndirDegree();
        v->decUndirDegree();
    }
    return false;
}

bool Graph::removeEdge(const std::string &uname, const std::string &vname) {
    return removeEdge(node(uname), node(vname));
}

Graph Graph::transpose() const {
    Graph transposed_graph = *this;
    transposed_graph.clear();
    for (const auto &node: this->nodeList())
        transposed_graph.addNode(node->name());
    for (auto it = edgeSet().begin(); it != edgeSet().end(); ++it)
        transposed_graph.setEdge(Edge(it).v()->name(), Edge(it).u()->name(), Edge(it).weight());
    return transposed_graph;
}

bool Graph::hasNode(Node *node) const {
    if (!node) return false;
    return _nodeSet.find(*node) != _nodeSet.end();
}

Edge Graph::edge(Node *u, Node *v) const {
    auto it = _edgeSet.find({u, v});
    if (_directed)
        return Edge(it);
    it = (it != _edgeSet.end()) ? it : _edgeSet.find({v, u});
    if (it == _edgeSet.end()) throw "Edge not found";
    return Edge(it);
}

Edge Graph::edge(const std::string &uname, const std::string &vname) const {
    return edge(node(uname), node(vname));
}

bool Graph::hasDirectedEdge(Node *u, Node *v) const {
    return _edgeSet.find(std::make_pair(u, v)) != _edgeSet.end();
}

bool Graph::hasEdge(Node *u, Node *v) const {
    return _directed ? hasDirectedEdge(u, v) : (hasDirectedEdge(u, v) || hasDirectedEdge(v, u));
}

bool Graph::hasEdge(const std::string &uname, const std::string &vname) const {
    return hasEdge(node(uname), node(vname));
}

namespace GraphType {
    std::ostream &operator<<(std::ostream &out, const Graph &graph) {
        out << graph.isDirected() << " " << graph.isWeighted() << "\n";
        out << graph.countNodes() << "\n";
        for (const auto &node: graph.nodeList())
            out << node->name() << " " << node->euclidePos().x() << " " << node->euclidePos().y() << "\n";
        out << graph.countEdges() << "\n";
        for (auto it = graph.edgeSet().begin(); it != graph.edgeSet().end(); ++it) {
            out << Edge(it).u()->name() << " " << Edge(it).v()->name() << " " << Edge(it).weight() << "\n";
        }
        return out;
    }
}
