#include "basis/headers/Node.h"
#include <utility>

GraphType::Node::Node(std::string name) {
    this->_name = std::move(name);
    this->_degNeg = 0;
    this->_degPos = 0;
    this->_deg = 0;
    this->_euclidePos = QPointF(0, 0);
}

GraphType::Node::Node(std::string name, QPointF pos) {
    this->_name = std::move(name);
    this->_degNeg = 0;
    this->_degPos = 0;
    this->_deg = 0;
    this->_euclidePos = pos;
}

