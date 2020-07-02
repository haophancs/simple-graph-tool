#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include "Graph.h"

namespace GraphType {
    class DirectedGraph : public Graph {
    public:
        DirectedGraph() : Graph() { this->_directed = true; }

        DirectedGraph(const DirectedGraph &obj)  : Graph(obj) {
            this->clear();
            for (auto &node: obj.nodeList())
                this->addNode(node->name());
            for (auto it = obj.edgeSet().begin(); it != obj.edgeSet().end(); ++it)
                this->setEdge(Edge(it).u()->name(), Edge(it).v()->name(), Edge(it).weight());
        }

        explicit DirectedGraph(int node_num) : Graph() { this->_directed = true; }
    };
}


#endif //DIRECTEDGRAPH_H
