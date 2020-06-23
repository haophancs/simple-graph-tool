#include "headers/Node.h"

Node::Node(std::string name, int id) {
    this->name = name;
    this->id = id;
    this->deg_pos = 0;
    this->deg_neg = 0;
    this->euclide_pos = QPointF(0, 0);
}

Node::Node(std::string name) {

    this->name = name;
    this->id = -1;
    this->deg_neg = 0;
    this->deg_pos = 0;
    this->euclide_pos = QPoint(0, 0);
}

Node::Node(std::string name, QPointF pos) {

    this->name = name;
    this->id = -1;
    this->deg_neg = 0;
    this->deg_pos = 0;
    this->euclide_pos = pos;
}
