//
// Created by haophancs on 30.06.2020.
//

#ifndef SIMPLE_GRAPH_TOOL_MATRIX_H
#define SIMPLE_GRAPH_TOOL_MATRIX_H

#include <vector>
#include <list>
#include <climits>
#include "Node.h"
#include "Arc.h"

namespace GraphType {
    class Matrix {
    protected:
        std::vector<Node *> _nodes;
        std::vector<std::vector<int>> _mat;
        bool _isWeighted = true;
        bool _isDirected = true;

        explicit Matrix(const std::list<Node *> &node_list, const ArcSet &arc_set, bool is_weighted = true, bool is_directed = true) {
            this->_isDirected = is_directed;
            this->_isWeighted = is_weighted;
            this->_nodes = std::vector<Node *>{ std::begin(node_list), std::end(node_list) };
        }

    public:
        Node *node(int i) const { return _nodes[i]; }
        int weight(int u, int v) const { return _mat[u][v]; }
        const std::vector<Node *>& nodes() const { return _nodes; }

        virtual ~Matrix() = default;
    };

    class AdjacencyMatrix : public Matrix {
    public:
        AdjacencyMatrix(const std::list<Node*>& node_list, const ArcSet& arc_set, bool is_weighted = true, bool is_directed = true)
            : Matrix(node_list, arc_set, is_weighted, is_directed) {
            auto default_w = is_directed ? INT_MAX : 0;

            this->_mat = std::vector<std::vector<int>>(node_list.size(), std::vector<int>(node_list.size(), default_w));
            std::unordered_map<std::string, int> name_index;
            for (int i = 0; i < _nodes.size(); ++i)
                name_index[_nodes[i]->name()] = i;
            for (auto it = arc_set.begin(); it != arc_set.end(); ++it) {
                auto arc = Arc(it);
                _mat[name_index[arc.u()->name()]][name_index[arc.v()->name()]] = arc.weight();
            }
        }
    };

    class IncidenceMatrix : public Matrix {
    public:
        IncidenceMatrix(const std::list<Node *>& node_list, const ArcSet& arc_set) : Matrix(node_list, arc_set, true,
                                                                                            true) {

        }
    };
}

#endif //SIMPLE_GRAPH_TOOL_MATRIX_H
