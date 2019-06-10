#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <vector>
#include <limits.h>
#include <fstream>
#include <memory>

class Graph {

  private:
    std::vector<std::vector<int>> adj_mat;
    std::vector<Node> node_list;

  public:
    Graph();
    Graph(int node_num);
    Graph getTranpose();
    void init(int node_num);
    void printAdjMat() const;
    void clear();

    void readFromFile(std::string file);
    void writeToFile(std::string file);

    inline int getNodeNum() const { return this->node_list.size(); }
    int findNodeIdByName(std::string name) const;
    std::vector<std::vector<int>> getAdjMatrix() const { return this->adj_mat; }
    std::vector<Node> getNodeList() const { return this->node_list; }
    std::vector<std::pair<int, int>> getArcList() const;

    bool hasThisNode(int id) const { return id >= 0 && id < getNodeNum(); }
    bool hasThisNode(std::string name) const { return hasThisNode(findNodeIdByName(name)); }

    bool setArc(int u, int v, int w = 1);
    bool setArc(std::string uname, std::string vname, int w = 1) {
        return setArc(findNodeIdByName(uname), findNodeIdByName(vname), w);
    }
    bool setArc(int u, std::string vname, int w = 1) {
        return setArc(u, findNodeIdByName(vname), w);
    }
    bool setArc(std::string uname, int v, int w = 1) {
        return setArc(findNodeIdByName(uname), v, w);
    }
    bool removeArc(int u, int v);
    bool removeArc(std::string uname, std::string vname) { return setArc(uname, vname, INT_MAX);}
    bool hasThisArc(int u, int v) const { return hasThisNode(u) && hasThisNode(v) && adj_mat[u][v] != INT_MAX && adj_mat[u][v] != 0; }
    bool hasThisArc(std::string uname, std::string vname) const { return hasThisArc(findNodeIdByName(uname), findNodeIdByName(vname)); }
    int getArcWeight(int u, int v) const {
        if (u == v)
            return 0;
        if (hasThisArc(u, v))
            return this->adj_mat[u][v];
        else
            return INT_MAX;
    }

    bool addNode(Node node);
    bool addNode(std::string nodename) { return addNode(Node(nodename));}
    bool removeNode(int id);
    bool removeNode(std::string nodename) { return removeNode(findNodeIdByName(nodename)); }
    bool isolateNode(int id);
    bool isolateNode(std::string nodename) { return isolateNode(findNodeIdByName(nodename)); }
    Node *getNodeByName(std::string name) {
        return getNode(findNodeIdByName(name));
    }
    Node *getNode(int id) {
      if (!hasThisNode(id))
        return nullptr;
      return &node_list[id];
    }
    std::string getNodeName(int id) const { return node_list[id].getName(); }
};

#endif
