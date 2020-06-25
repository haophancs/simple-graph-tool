#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <utility>
#include <vector>
#include <climits>
#include <fstream>
#include <memory>

class Graph {

private:
    std::vector<std::vector<int>> adjMatrix;
    std::vector<Node> nodeList;

public:
    Graph();

    explicit Graph(int node_num);

    void init(int node_num);

    void printAdjMatrix() const;

    void clear();

    void readFromFile(const std::string &file);

    void writeToFile(const std::string &file) const ;

    inline int getNodeNum() const { return this->nodeList.size(); }

    int findNodeIdByName(const std::string &name) const;

    Graph getTranspose() const;

    std::vector<std::vector<int>> getAdjMatrix() const { return this->adjMatrix; }

    std::vector<Node> getNodeList() const { return this->nodeList; }

    std::vector<std::pair<int, int>> getArcList() const;

    bool hasThisNode(int id) const { return id >= 0 && id < getNodeNum(); }

    bool hasThisNode(const std::string &name) const { return hasThisNode(findNodeIdByName(name)); }

    bool setArc(int u, int v, int w = 1);

    bool setArc(const std::string &uname, const std::string &vname, int w = 1) {
        return setArc(findNodeIdByName(uname), findNodeIdByName(vname), w);
    }

    bool removeArc(int u, int v);

    bool removeArc(const std::string &uname, const std::string &vname) { return setArc(uname, vname, INT_MAX); }

    bool hasThisArc(int u, int v) const {
        return hasThisNode(u) && hasThisNode(v) && adjMatrix[u][v] != INT_MAX && adjMatrix[u][v] != 0;
    }

    bool hasThisArc(const std::string &uname, const std::string &vname) const {
        return hasThisArc(findNodeIdByName(uname), findNodeIdByName(vname));
    }

    int getArcWeight(int u, int v) const;

    bool addNode(Node node);

    bool addNode(std::string nodename) { return addNode(Node(std::move(nodename))); }

    bool removeNode(int id);

    bool removeNode(const std::string &nodename) { return removeNode(findNodeIdByName(nodename)); }

    bool isolateNode(int id);

    bool isolateNode(const std::string &nodename) { return isolateNode(findNodeIdByName(nodename)); }

    const Node *getNode(int id);

    const Node *getNodeByName(const std::string &name) { return getNode(findNodeIdByName(name)); }

    std::string getNodeName(int id) const { return nodeList[id].getName(); }

    void setNodeName(int id, std::string newName);

    void setNodeName(std::string oldName, std::string newName);
};

#endif
