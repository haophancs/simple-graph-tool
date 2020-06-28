#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <utility>
#include <QPointF>

class Node {

private:
    int _degPos;
    int _degNeg;
    std::string _name;
    QPointF _euclidePos;

    void incPositiveDeg() { this->_degPos++; }

    void incNegativeDeg() { this->_degNeg++; }

    void decPositiveDeg() { if (this->_degPos > 0) this->_degPos--; }

    void decNegativeDeg() { if (this->_degNeg > 0) this->_degNeg--; }

    void setName(std::string newName) { this->_name = std::move(newName); }

    friend class Graph;
    Node() {
        this->_degPos = this->_degNeg = 0;
    }

public:

    explicit Node(std::string name);

    explicit Node(std::string name, QPointF);

    int negativeDegree() const { return this->_degNeg; }

    int positiveDegree() const { return this->_degPos; }

    int degree() const { return this->_degPos + this->_degNeg; }

    QPointF euclidePos() const { return this->_euclidePos; }

    void setEuclidePos(const QPointF &pos) { this->_euclidePos = pos; }

    std::string name() const { return this->_name; }

    bool operator==(const Node &other) const { return (this->_name == other._name); }

};

namespace std {
    template<>
    struct hash<Node> {
        size_t
        operator()(const Node &obj) const {
            return hash<std::string>()(obj.name());
        }
    };
}

#endif
