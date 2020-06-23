#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <utility>
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
    explicit Graph(int node_num);
    Graph getTranspose();
    void init(int node_num);
    void printAdjMat() const;
    void clear();

    void readFromFile(const std::string& file);
    void writeToFile(const std::string& file);

    inline int getNodeNum() const { return this->node_list.size(); }
    int findNodeIdByName(const std::string& name) const;
    std::vector<std::vector<int>> getAdjMatrix() const { return this->adj_mat; }
    std::vector<Node> getNodeList() const { return this->node_list; }
    std::vector<std::pair<int, int>> getArcList() const;

    bool hasThisNode(int id) const { return id >= 0 && id < getNodeNum(); }
    bool hasThisNode(const std::string& name) const { return hasThisNode(findNodeIdByName(name)); }

    bool setArc(int u, int v, int w = 1);
    bool setArc(const std::string& uname, const std::string& vname, int w = 1) {
        return setArc(findNodeIdByName(uname), findNodeIdByName(vname), w);
    }
    bool setArc(int u, const std::string& vname, int w = 1) { return setArc(u, findNodeIdByName(vname), w); }
    bool setArc(const std::string& uname, int v, int w = 1) { return setArc(findNodeIdByName(uname), v, w); }
    bool removeArc(int u, int v);
    bool removeArc(const std::string& uname, const std::string& vname) { return setArc(uname, vname, INT_MAX);}
    bool hasThisArc(int u, int v) const { return hasThisNode(u) && hasThisNode(v) && adj_mat[u][v] != INT_MAX && adj_mat[u][v] != 0; }
    bool hasThisArc(const std::string& uname, const std::string& vname) const { return hasThisArc(findNodeIdByName(uname), findNodeIdByName(vname)); }
    int getArcWeight(int u, int v) const;

    bool addNode(Node node);
    bool addNode(std::string nodename) { return addNode(Node(std::move(nodename)));}
    bool removeNode(int id);
    bool removeNode(const std::string& nodename) { return removeNode(findNodeIdByName(nodename)); }
    bool isolateNode(int id);
    bool isolateNode(const std::string& nodename) { return isolateNode(findNodeIdByName(nodename)); }
    Node *getNode(int id);
    Node *getNodeByName(const std::string& name) { return getNode(findNodeIdByName(name)); }
    std::string getNodeName(int id) const { return node_list[id].getName(); }
};

#endif
