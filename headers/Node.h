#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <QPoint>
#include <utility>

class Node {

private:
    int id;
    int degPos;
    int degNeg;
    std::string name;
    QPointF euclidePos;

    void setId(int newId) { this->id = newId; }

    void incPositiveDeg() { this->degPos++; }

    void incNegativeDeg() { this->degNeg++; }

    void decPositiveDeg() { if (this->degPos > 0) this->degPos--; }

    void decNegativeDeg() { if (this->degNeg > 0) this->degNeg--; }

    void isolate() { this->degNeg = this->degPos = 0; }

    void setName(std::string newName) { this->name = std::move(newName); }

    friend class Graph;

public:
    explicit Node(std::string name, int id);

    explicit Node(std::string name);

    explicit Node(std::string name, QPointF pos);

    QPointF getEuclidePos() const { return this->euclidePos; }

    void setEuclidePos(QPointF pos) { this->euclidePos = pos; }

    int getNegativeDeg() const { return this->degNeg; }

    int getPositiveDeg() const { return this->degPos; }

    int getDeg() const { return this->degPos + this->degNeg; }

    int getId() const { return this->id; }

    std::string getName() const { return this->name; }
};

#endif
