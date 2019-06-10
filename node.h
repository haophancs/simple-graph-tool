#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <QPoint>
class Node {

private:
    int id;
    int deg_pos;
    int deg_neg;
    std::string name;
    QPointF euclide_pos;

    void setId(int id) { this->id = id; }
    void incPositiveDeg() { this->deg_pos++; }
    void incNegativeDeg() { this->deg_neg++;  }
    void decPositiveDeg() { if (this->deg_pos > 0) this->deg_pos--; }
    void decNegativeDeg() { if (this->deg_neg > 0) this->deg_neg--; }
    void isolate() { this->deg_neg = this->deg_pos = 0; }

    friend class NodeItem;
    friend class Graph;

public:
    Node(std::string name, int id);
    Node(std::string name);
    Node(std::string name, QPointF pos);
    std::string getName() const { return this->name; }
    void setName(std::string name) { this->name = name; }
    void setEuclidePos(QPointF pos) { this->euclide_pos = pos; }

    QPointF getEuclidePos() const { return this->euclide_pos; }

    int getNegativeDeg() const {return this->deg_neg; }
    int getPositiveDeg() const {return this->deg_pos; }
    int getDeg() const {return this->deg_pos + this->deg_neg; }
    int getId() const { return this->id; }
};

#endif
