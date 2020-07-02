#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Edge.h"
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

    protected:
        EdgeSet _edgeSet;
        std::unordered_set<Node> _nodeSet;
        std::list<Node *> _cachedNodeList;
        bool _directed{};
        bool _weighted{};

    public:
        Graph() = default;

        explicit Graph(int node_num);

        Graph(const Graph &obj);

        void init(int node_num);

        void clear();

        void readFromFile(const std::string &file);

        void writeToFile(const std::string &file) const;

        AdjacencyMatrix adjMatrix() const { return AdjacencyMatrix(_cachedNodeList, _edgeSet); }

        const EdgeSet& edgeSet() const { return this->_edgeSet; }

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

        inline int countEdges() const { return this->_edgeSet.size(); }

        Edge edge(const std::string& uname, const std::string& vname) const {
            auto it = _edgeSet.find({node(uname), node(vname) });
            return Edge(it);
        }

        bool setEdge(Node *u, Node *v, int w);

        bool setEdge(const std::string &uname, const std::string &vname, int w);

        bool removeEdge(Node *u, Node *v);

        bool removeEdge(const std::string &uname, const std::string &vname);

        inline bool hasEdge(Node *u, Node *v) const { return _edgeSet.find(std::make_pair(u, v)) != _edgeSet.end(); }

        inline bool hasEdge(const std::string &uname, const std::string &vname) const {
            return hasEdge(node(uname), node(vname));
        }

        int weight(Node *u, Node *v) const;

        int weight(const std::string &uname, const std::string &vname) const;

        void clearEdges() { this->_edgeSet.clear(); }

        Graph transpose() const;

        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

        std::string nextNodeName() const;
    };
}
#endif
