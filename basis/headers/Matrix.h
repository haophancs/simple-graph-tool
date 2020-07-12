#ifndef SIMPLE_GRAPH_TOOL_MATRIX_H
#define SIMPLE_GRAPH_TOOL_MATRIX_H

#include <vector>
#include <list>
#include <climits>
#include "Node.h"
#include "Edge.h"
#include <QDebug>
#include <queue>

namespace GraphType {
    class Matrix {
    protected:
        std::vector<Node *> _nodes;
        std::vector<std::vector<int>> _mat;
        bool _isDirected = true;

        explicit Matrix(const std::list<Node *> &node_list, const EdgeSet &edge_set, bool is_directed) {
            this->_isDirected = is_directed;
            this->_nodes = std::vector<Node *>{std::begin(node_list), std::end(node_list)};
            std::sort(_nodes.begin(), _nodes.end(), [](const Node *n1, const Node *n2) {
                return n1->name() < n2->name();
            });
        }

    public:
        Node *node(int i) const { return _nodes[i]; }

        int value(int u, int v) const { return _mat[u][v]; }

        const std::vector<Node *> &nodes() const { return _nodes; }

        std::vector<std::vector<int>> mat() const { return _mat; }

        virtual ~Matrix() = default;
    };

    class AdjacencyMatrix : public Matrix {
    public:
        AdjacencyMatrix(const std::list<Node *> &node_list, const EdgeSet &edge_set, bool is_directed,
                        int invalid_value)
                : Matrix(node_list, edge_set, is_directed) {
            this->_mat = std::vector<std::vector<int>>(node_list.size(),
                                                       std::vector<int>(node_list.size(), invalid_value));

            std::unordered_map<std::string, int> name_index;
            for (int i = 0; i < _nodes.size(); ++i) {
                name_index[_nodes[i]->name()] = i;
            }
            for (auto it = edge_set.begin(); it != edge_set.end(); ++it) {
                auto edge = Edge(it);
                _mat[name_index[edge.u()->name()]][name_index[edge.v()->name()]] = edge.weight();
                if (!is_directed)
                    _mat[name_index[edge.v()->name()]][name_index[edge.u()->name()]] = edge.weight();
            }
        }
    };

    class IncidenceMatrix : public Matrix {
    private:
        std::vector<Edge> _edges;

        void setEdges(const EdgeSet &edge_set) {
            auto comp = [&](EdgeSet::const_iterator it1, EdgeSet::const_iterator it2) {
                return it1->first.first->name() + "-" + it1->first.second->name()
                       > it2->first.first->name() + "-" + it2->first.second->name();
            };
            std::priority_queue<EdgeSet::const_iterator, std::vector<EdgeSet::const_iterator>, decltype(comp)> pq(comp);
            for (auto it = edge_set.begin(); it != edge_set.end(); ++it) {
                pq.push(it);
            }
            while (!pq.empty()) {
                auto it = pq.top();
                _edges.emplace_back(Edge(it));
                pq.pop();
            }
        }

    public:
        IncidenceMatrix(const std::list<Node *> &node_list, const EdgeSet &edge_set, bool is_directed)
                : Matrix(node_list, edge_set, is_directed) {
            setEdges(edge_set);
            this->_mat = std::vector<std::vector<int>>(_nodes.size(), std::vector<int>(_edges.size(), 0));

            std::unordered_map<std::string, int> name_index;
            for (int i = 0; i < _nodes.size(); ++i)
                name_index[_nodes[i]->name()] = i;

            for (int j = 0; j < _edges.size(); ++j) {
                int i = name_index[_edges[j].u()->name()];
                _mat[i][j] = _edges[j].weight();
                i = name_index[_edges[j].v()->name()];
                _mat[i][j] = (_isDirected ? -1 : 1) * _edges[j].weight();
            }
        }

        const std::vector<Edge> &edges() const { return this->_edges; }
    };
}

#endif //SIMPLE_GRAPH_TOOL_MATRIX_H
