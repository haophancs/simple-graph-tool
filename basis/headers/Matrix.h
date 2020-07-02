//
// Created by haophancs on 30.06.2020.
//

#ifndef SIMPLE_GRAPH_TOOL_MATRIX_H
#define SIMPLE_GRAPH_TOOL_MATRIX_H

#include <vector>
#include <list>
#include <climits>
#include "Node.h"
#include "Edge.h"

namespace GraphType {
    class Matrix {
    protected:
        std::vector<Node *> _nodes;
        std::vector<std::vector<int>> _mat;
        bool _isDirected = true;

        explicit Matrix(const std::list<Node *> &node_list, const EdgeSet &edge_set, bool is_directed,
                        int invalid_value) {
            this->_isDirected = is_directed;
            this->_nodes = std::vector<Node *>{std::begin(node_list), std::end(node_list)};
        }

    public:
        Node *node(int i) const { return _nodes[i]; }
        int weight(int u, int v) const { return _mat[u][v]; }
        const std::vector<Node *>& nodes() const { return _nodes; }

        virtual ~Matrix() = default;
    };

    class AdjacencyMatrix : public Matrix {
    public:
        AdjacencyMatrix(const std::list<Node *> &node_list, const EdgeSet &edge_set, bool is_directed,
                        int invalid_value)
                : Matrix(node_list, edge_set, is_directed, invalid_value) {
            this->_mat = std::vector<std::vector<int>>(node_list.size(),
                                                       std::vector<int>(node_list.size(), invalid_value));
            std::unordered_map<std::string, int> name_index;
            for (int i = 0; i < _nodes.size(); ++i) {
                name_index[_nodes[i]->name()] = i;
                _mat[i][i] = 0;
            }
            for (auto it = edge_set.begin(); it != edge_set.end(); ++it) {
                auto edge = Edge(it);
                _mat[name_index[edge.u()->name()]][name_index[edge.v()->name()]] = edge.weight();
                if (!is_directed)
                    _mat[name_index[edge.v()->name()]][name_index[edge.u()->name()]] = edge.weight();
            }
        }
    };
}

#endif //SIMPLE_GRAPH_TOOL_MATRIX_H
