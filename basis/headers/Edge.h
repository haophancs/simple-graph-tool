#ifndef EDGE_H
#define EDGE_H

#include <unordered_map>
#include "Node.h"

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

namespace GraphType {
    typedef std::pair<Node *, Node *> NodePair;
    typedef std::unordered_map<NodePair, int> EdgeSet;

    struct Edge {

        Edge(NodePair &pair, int &w) : _nodePair(pair), _weight(w) {}

        explicit Edge(EdgeSet::iterator &it) : _nodePair(it->first), _weight(it->second) {}

        explicit Edge(EdgeSet::const_iterator &it) : _nodePair(it->first), _weight(it->second) {}

        Node *u() const { return _nodePair.first; }

        Node *v() const { return _nodePair.second; }

        const int &weight() const { return _weight; }

        friend class Graph;

    private:
        const NodePair &_nodePair{};
        const int &_weight{};
    };
}
#endif
