#include "headers/Node.h"

#include <utility>

Node::Node(std::string name, int id) {
    this->name = std::move(name);
    this->id = id;
    this->degPos = 0;
    this->degNeg = 0;
    this->euclidePos = QPointF(0, 0);
}

Node::Node(std::string name) {
    this->name = std::move(name);
    this->id = -1;
    this->degNeg = 0;
    this->degPos = 0;
    this->euclidePos = QPoint(0, 0);
}

Node::Node(std::string name, QPointF pos) {
    this->name = std::move(name);
    this->id = -1;
    this->degNeg = 0;
    this->degPos = 0;
    this->euclidePos = pos;
}
