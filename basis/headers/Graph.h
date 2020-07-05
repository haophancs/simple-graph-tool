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
        const bool _directed;
        const bool _weighted;
        const int _invalidValue;
        const std::pair<int, int> _weightRange;

        static int _calcInvalid(bool directed, bool weighted) {
            return directed ? (weighted ? INT_MAX : 0) : 0;
        }

        static std::pair<int, int> _calcWeightRange(bool weighted) {
            auto _max = weighted ? INT_MAX - 1 : 1;
            auto _min = 1;
            return {_min, _max};
        }

        void _init(int node_num);

    public:
        explicit Graph(bool directed, bool weighted) :
                _directed(directed),
                _weighted(weighted),
                _invalidValue(_calcInvalid(directed, weighted)),
                _weightRange(_calcWeightRange(weighted)) {}

        explicit Graph(int node_num, bool directed, bool weighted);

        Graph(const Graph &obj);

        bool isWeighted() const { return this->_weighted; }

        bool isUnweighted() const { return !(this->_weighted); }

        bool isDirected() const { return this->_directed; }

        bool isUndirected() const { return !(this->_directed); }

        int invalidValue() const { return this->_invalidValue; }

        std::pair<int, int> weightRange() const { return this->_weightRange; }

        void clear();

        static Graph readFromFile(const std::string &file);

        static void writeToFile(const std::string &file, const Graph &graph);

        AdjacencyMatrix adjMatrix() const {
            return AdjacencyMatrix(_cachedNodeList, _edgeSet, _directed, _invalidValue);
        }

        IncidenceMatrix incidenceMatrix() const {
            return IncidenceMatrix(_cachedNodeList, _edgeSet, _directed);
        }

        const EdgeSet &edgeSet() const { return this->_edgeSet; }

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

        Edge edge(Node *u, Node *v) const;

        Edge edge(const std::string &uname, const std::string &vname) const;

    private:
        bool hasDirectedEdge(Node *u, Node *v) const;

    public:
        bool setEdge(Node *u, Node *v) { return setEdge(u, v, 1); }

        bool setEdge(const std::string &uname, const std::string &vname);

        bool setEdge(Node *u, Node *v, int w);

        bool setEdge(const std::string &uname, const std::string &vname, int w);

        bool removeEdge(Node *u, Node *v);

        bool removeEdge(const std::string &uname, const std::string &vname);

        bool hasEdge(Node *u, Node *v) const;

        bool hasEdge(const std::string &uname, const std::string &vname) const;

        int weight(Node *u, Node *v) const;

        int weight(const std::string &uname, const std::string &vname) const;

        void clearEdges() { this->_edgeSet.clear(); }

        Graph transpose() const;

        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

        std::string nextNodeName() const;
    };
}
#endif
