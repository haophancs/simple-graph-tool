#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include "Graph.h"
#include <queue>
#include <stack>
#include <list>

using namespace GraphType;

class GraphUtils {

private:
    GraphUtils() = default;

    static void DFSUtil(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                        std::list<std::string> &steps);

public:

    static std::list<std::string> BFS(const Graph *graph, std::string source = "");

    static std::list<std::string> DFS(const Graph *graph, std::string source = "");

    static std::list<std::pair<std::string, std::string>> BFSToDemo(const Graph *graph, const std::string &source);

    static std::list<std::pair<std::string, std::string>> DFSToDemo(const Graph *graph, const std::string &source);

    static std::list<std::string> Dijkstra(const Graph *graph, const std::string &start, const std::string &goal);

    static std::list<std::pair<std::string, std::string>> spanningTreeDFS(const Graph *graph, const std::string &source);

    static std::list<std::pair<std::string, std::string>> spanningTreeBFS(const Graph *graph, const std::string &source);

    static std::list<std::pair<std::string, std::string>> Prim(const Graph *graph, std::string source = "");

    static std::list<std::list<std::string>> connectedComponents(const Graph *graph);

    static std::list<std::list<std::string>> weaklyConnectedComponents(const Graph *graph);

    static std::list<std::list<std::string>> displayConnectedComponents(const Graph *graph, bool strong = true);

    static std::list<std::pair<std::string, std::string>> getBridges(const Graph *graph);

    static std::list<std::pair<std::string, std::string>> displayBridges(const Graph *graph);

    static bool isConnectedFromUtoV(const Graph *graph, const std::string &uname, const std::string &vname);

    static bool isAllConnected(const Graph *graph);

    static bool isAllWeaklyConnected(const Graph *graph);

    static std::list<std::string> getArticulationNodes(const Graph *graph);

    static std::list<std::string> displayArticulationNodes(const Graph *graph);

    static std::list<std::string> getHamiltonianCircuit(const Graph *graph, std::string source = "");

    static std::list<std::string> getEulerianCircuit(const Graph *_graph, std::string source = "");

    static std::list<std::list<std::string>> displayAllHamiltonianCircuits(const Graph *graph);

    static std::list<std::list<std::string>> displayAllEulerianCircuits(const Graph *graph);

    static std::list<std::string> getTopoSortResult(const Graph *graph);

    static std::list<std::string> displayTopoSort(const Graph *graph);

    static std::list<std::pair<std::string, int>> getColoringResult(const Graph *graph, std::string source = "");

    static std::list<std::pair<std::string, std::string>> displayColoring(const Graph *graph, std::string source = "");

    static bool isCycle(const Graph *graph);

    static std::list<std::string> AStar(const Graph *graph, std::string start, std::string goal);

    static std::list<std::string> Hierholzer(Graph &graph, const std::string& source);

    static std::list<std::list<std::string>> displayAllCycles(const Graph *graph);

    static std::list<std::list<std::string>> Gotlieb(const Graph *graph);
};

#endif
