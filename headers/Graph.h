#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <climits>
#include <fstream>
#include <memory>
#include <unordered_map>

struct AdjMatrix {
    std::vector<Node *> nodes;
    std::vector<std::vector<int>> matrix;
};

class Arc {
    Node *_start;
    Node *_end;
    int _weight;

public:
    Arc(Node *start, Node *end, int weight) {
        this->_start = start;
        this->_end = end;
        this->_weight = weight;
    }

    Node *start() const { return this->_start; }

    Node *end() const { return this->_end; }

    int weight() const { return this->_weight; }
};

namespace std {
    template<class T1, class T2>
    struct hash<pair<T1, T2>> {
        size_t
        operator()(const pair<T1, T2> &p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
}

class Graph {

private:
    std::unordered_map<std::pair<Node *, Node *>, int> _arcSet;
    std::unordered_set<Node> _nodeSet;
    std::list<Node *> _cachedNodeList;
    int max_size = 0;

public:
    Graph() = default;

    explicit Graph(int nodeNum);

    void init(int nodeNum);

    void clear();

    void readFromFile(const std::string &file);

    void writeToFile(const std::string &file) const;

    AdjMatrix adjMatrix() const;

    std::list<Arc> arcList() const;

    std::list<Node *> nodeList() const { return this->_cachedNodeList; };

    inline int countNodes() const { return this->_nodeSet.size(); }

    Node *node(const std::string &node_name) const;

    inline bool hasNode(Node *node) const;

    inline bool hasNode(const std::string &node_name) const { return _nodeSet.find(Node(node_name)) != _nodeSet.end(); }

    bool addNode(const Node &node);

    bool addNode(std::string node_name = "");

    bool removeNode(Node *node);

    bool removeNode(const std::string &name);

    bool isolateNode(Node *node);

    bool isolateNode(const std::string &name);

    bool setNodeName(Node *node, const std::string &node_name) const;

    bool setNodeName(const std::string &old_name, const std::string &new_name) const;

    inline int countArcs() const { return this->_arcSet.size(); }

    bool setArc(Node *u, Node *v, int w = 1);

    bool setArc(const std::string &uname, const std::string &vname, int w = 1);

    bool removeArc(Node *u, Node *v);

    bool removeArc(const std::string &uname, const std::string &vname);

    inline bool hasArc(Node *u, Node *v) const { return _arcSet.find(std::make_pair(u, v)) != _arcSet.end(); }

    inline bool hasArc(const std::string &uname, const std::string &vname) const {
        return hasArc(node(uname), node(vname));
    }

    int weight(Node *u, Node *v) const;

    int weight(const std::string &uname, const std::string &vname) const;

    void clearArcs() { this->_arcSet.clear(); }

    Graph transpose() const;

    friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

    std::string nextNodeName() const;
};

#endif
