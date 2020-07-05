#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <utility>
#include <QPointF>

namespace GraphType {
    class Node {

    private:
        int _degPos;
        int _degNeg;
        int _deg;
        std::string _name;
        QPointF _euclidePos;

        void incPosDegree() { this->_degPos++; }

        void incNegDegree() { this->_degNeg++; }

        void decPosDegree() { if (this->_degPos > 0) this->_degPos--; }

        void decNegDegree() { if (this->_degNeg > 0) this->_degNeg--; }

        void incUndirDegree() { this->_deg++; }

        void decUndirDegree() { if (this->_deg > 0) this->_deg--; }

        void setName(std::string newName) { this->_name = std::move(newName); }

        friend class Graph;

        Node() {
            this->_degPos = this->_degNeg = this->_deg = 0;
        }

    public:

        explicit Node(std::string name);

        explicit Node(std::string name, QPointF);

        int negDegree() const { return this->_degNeg; }

        int posDegree() const { return this->_degPos; }

        int undirDegree() const { return this->_deg; }

        int dirDegree() const { return this->_degPos + this->_degNeg; }

        QPointF euclidePos() const { return this->_euclidePos; }

        void setEuclidePos(const QPointF &pos) { this->_euclidePos = pos; }

        std::string name() const { return this->_name; }

        bool operator==(const Node &other) const { return (this->_name == other._name); }

        bool operator<(const Node &other) const { return (this->_name < other._name); }

        bool operator>(const Node &other) const { return (this->_name > other._name); }
    };
}

namespace std {
    template<>
    struct hash<GraphType::Node> {
        size_t
        operator()(const GraphType::Node &obj) const {
            return hash<std::string>()(obj.name());
        }
    };
}
#endif
