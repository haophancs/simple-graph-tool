#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include "Graph.h"
#include <queue>
#include <stack>
#include <list>

class GraphUtils {

private:
    static void DFSUtil(const Graph& graph, int v, std::vector<bool> &visited, std::list<int> &steps);

public:

    static std::list<int> BFS(const Graph& graph, int source = 0);
    static std::list<int> DFS(const Graph& graph, int source = 0);
    static std::list<std::pair<int, int>> BfsToDemo(const Graph& graph, int source);
    static std::list<std::pair<int, int>> DfsToDemo(const Graph& graph, int source);

    static std::list<int> Dijkstra(Graph &graph, int start, int goal);
    static std::list<std::pair<int, int>> Prim(const Graph& graph, int source = 0);

    static std::list<std::list<int>> stronglyConnectedComponents(Graph graph);
    static std::list<std::list<int>> weaklyConnectedComponents(const Graph& graph);
    static std::list<std::list<int>> displayConnectedComponents(const Graph& graph, bool strong = true);
    static std::list<std::pair<int, int>> getBridges(const Graph& graph);
    static std::list<std::pair<int, int>> displayBridges(const Graph& graph);

    static bool isConnectedFromUtoV(const Graph& graph, int u, int v);
    static bool isAllStronglyConnected(const Graph& graph);
    static bool isAllWeaklyConnected(const Graph& graph);
    static std::list<int> getArticulationNodes(const Graph& graph);
    static std::list<int> displayArticulationNodes(const Graph& graph);

    static std::list<int> getHamiltonianCycle(const Graph& graph, int source = 0);
    static std::list<int> getEulerianCircuit(Graph graph, int source = 0);
    static std::list<std::list<int>> displayHamiltonianCycle(const Graph& graph);
    static std::list<std::list<int>> displayEulerianCircuit(const Graph& graph);

    std::list<int> getTopoSortResult(Graph graph);
    std::list<int> displayTopoSort(Graph graph);

    std::list<int> getColoringResult(Graph graph, int source = 0);
    std::list<int> displayColoring(Graph graph, int source = 0);
};

#endif
