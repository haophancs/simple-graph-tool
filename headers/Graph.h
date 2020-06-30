#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Arc.h"
#include "Matrix.h"
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <climits>
#include <fstream>
#include <memory>
#include <unordered_map>

namespace GraphType {

    class Graph {

    private:
        ArcSet _arcSet;
        std::unordered_set<Node> _nodeSet;
        std::list<Node *> _cachedNodeList;

    public:
        Graph() = default;

        explicit Graph(int nodeNum);

        Graph(const Graph &obj);

        void init(int node_num);

        void clear();

        void readFromFile(const std::string &file);

        void writeToFile(const std::string &file) const;

        AdjacencyMatrix adjMatrix() const { return AdjacencyMatrix(_cachedNodeList, _arcSet); }

        const ArcSet& arcSet() const { return this->_arcSet; }

        std::list<Node *> nodeList() const { return this->_cachedNodeList; }

        inline int countNodes() const { return this->_nodeSet.size(); }

        Node *node(const std::string &node_name) const;

        bool hasNode(Node *node) const;

        bool hasNode(const std::string &node_name) const {
            return _nodeSet.find(Node(node_name)) != _nodeSet.end();
        }

        bool addNode(const Node &node);

        bool addNode(std::string node_name = "");

        bool removeNode(Node *node);

        bool removeNode(const std::string &name);

        bool isolateNode(Node *node);

        bool isolateNode(const std::string &name);

        bool setNodeName(Node *node, const std::string &new_name);

        bool setNodeName(const std::string &old_name, const std::string &new_name);

        inline int countArcs() const { return this->_arcSet.size(); }

        Arc arc(const std::string& uname, const std::string& vname) const {
            auto it = _arcSet.find({ node(uname), node(vname) });
            return Arc(it);
        }

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
}
#endif
