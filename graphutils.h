#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include "graph.h"
#include <queue>
#include <stack>
#include <list>

class GraphUtils {

private:
    void DFSUtil(Graph &graph, int v, std::vector<bool> &visited, std::list<int> &steps);

public:
    std::list<std::pair<int, int>> BfsToDemo(Graph graph, int source);
    std::list<std::pair<int, int>> DfsToDemo(Graph graph, int source);

    std::list<int> BFS(Graph &graph, int source = 0);
    std::list<int> DFS(Graph &graph, int source = 0);
    void displayBFS(Graph &graph, int source = 0);
    void displayDFS(Graph &graph, int source = 0);

    std::list<int> Dijkstra(Graph &graph, int start, int goal);
    std::list<std::pair<int, int>> Prim(Graph &graph, int source = 0);

    std::list<std::list<int>> stronglyConnectedComponents(Graph &graph);
    std::list<std::list<int>> weaklyConnectedComponents(Graph &graph);
    std::list<std::list<int>> displayConnectedComponents(Graph &graph, bool strong = true);
    std::list<std::pair<int, int>> getBridges(Graph &graph);
    std::list<std::pair<int, int>> displayBridges(Graph &graph);

    bool isConnectedFromUtoV(Graph graph, int u, int v);
    bool isAllStronglyConnected(Graph graph);
    bool isAllWeaklyConnected(Graph graph);
    std::list<int> getArticulationNodes(Graph graph);
    std::list<int> displayArticulationNodes(Graph graph);

    std::list<int> getHamiltonianCycle(Graph graph, int source = 0);
    std::list<int> getEulerianCircuit(Graph graph, int source = 0);
    std::list<std::list<int>> displayHamiltonianCycle(Graph graph);
    std::list<std::list<int>> displayEulerianCircuit(Graph graph);

    std::list<int> getTopoSortResult(Graph graph);
    std::list<int> displayTopoSort(Graph graph);

    std::list<int> getColoringResult(Graph graph, int source = 0);
    std::list<int> displayColoring(Graph graph, int source = 0);
};

#endif
