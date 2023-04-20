#include "basis/headers/GraphUtils.h"
#include <unordered_map>
#include <utility>
#include <QString>
#include <QDebug>

std::list<std::pair<std::string, std::string>> GraphUtils::BFSToDemo(const Graph *graph, const std::string &source) {
    std::list<std::pair<std::string, std::string>> result;
    if (!graph->hasNode(source)) return result;

    auto nodes = graph->nodeList();
    std::queue<std::string> q;
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, std::string> parent;
    q.push(source);
    visited[source] = true;
    std::cout << "BFS (source = " << source << "): ";

    while (!q.empty()) {
        auto vname = q.front();
        std::cout << vname << " ";
        result.emplace_back(parent[vname], vname);
        q.pop();

        for (auto &adj : nodes) {
            if (graph->hasEdge(vname, adj->name()) && !visited[adj->name()]) {
                visited[adj->name()] = true;
                q.push(adj->name());
                parent[adj->name()] = vname;
            }
        }
    }
    std::cout << "\n";
    return result;
}

std::list<std::pair<std::string, std::string>> GraphUtils::DFSToDemo(const Graph *graph, const std::string &source) {
    std::list<std::pair<std::string, std::string>> result;
    if (!graph->hasNode(source)) return result;

    auto nodes = graph->nodeList();
    std::stack<std::string> s;
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, std::string> parent;
    s.push(source);
    visited[source] = true;

    std::cout << "DFS (source = " << source << "): ";
    while (!s.empty()) {
        auto vname = s.top();
        std::cout << vname << " ";
        visited[vname] = true;
        result.emplace_back(parent[vname], vname);
        s.pop();

        for (auto &adj: nodes) {
            if (graph->hasEdge(vname, adj->name()) && !visited[adj->name()]) {
                s.push(adj->name());
                parent[adj->name()] = vname;
            }
        }
    }
    std::cout << "\n";
    return result;
}

std::list<std::string> GraphUtils::BFS(const Graph *graph, std::string source) {
    auto nodes = graph->nodeList();
    if (source.empty())
        source = nodes.front()->name();
    std::list<std::string> steps;
    if (!graph->hasNode(source)) return steps;
    std::queue<std::string> q;
    std::unordered_map<std::string, bool> visited;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        auto vname = q.front();
        steps.push_back(vname);
        q.pop();
        for (auto &adj: nodes) {
            if (graph->hasEdge(vname, adj->name()) && !visited[adj->name()]) {
                visited[adj->name()] = true;
                q.push(adj->name());
            }
        }
    }
    return steps;
}

void GraphUtils::DFSUtil(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                         std::list<std::string> &steps) {
    visited[vname] = true;
    steps.push_back(vname);
    for (auto &adj: graph->nodeList()) {
        if (graph->hasEdge(vname, adj->name()) && !visited[adj->name()])
            DFSUtil(graph, adj->name(), visited, steps);
    }
}

void UndirectedDFSUtil(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                       std::list<std::string> &steps) {
    visited[vname] = true;
    steps.push_back(vname);
    for (auto &adj: graph->nodeList()) {
        if ((graph->hasEdge(vname, adj->name()) || graph->hasEdge(adj->name(), vname)) && !visited[adj->name()])
            UndirectedDFSUtil(graph, adj->name(), visited, steps);
    }
}

int DFSCount(const Graph &graph, const std::string &uname, std::unordered_map<std::string, bool> &visited) {
    visited[uname] = true;
    int count = 1;
    for (auto v: graph.nodeList())
        if (graph.hasEdge(uname, v->name()) && !visited[v->name()])
            count += DFSCount(graph, v->name(), visited);
    return count;
}

std::list<std::string> GraphUtils::DFS(const Graph *graph, std::string source) {
    auto nodes = graph->nodeList();
    if (source.empty())
        source = nodes.front()->name();
    std::list<std::string> steps;
    std::unordered_map<std::string, bool> visited;
    if (!graph->hasNode(source)) return steps;
    DFSUtil(graph, source, visited, steps);
    return steps;
}

bool GraphUtils::isConnectedFromUtoV(const Graph *graph, const std::string &uname, const std::string &vname) {
    if (!graph->hasNode(uname) || !graph->hasNode(vname)) return false;
    std::unordered_map<std::string, bool> visited;
    std::list<std::string> steps;
    DFSUtil(graph, uname, visited, steps);
    return visited[vname];
}

bool GraphUtils::isAllConnected(const Graph *graph) {
    auto nodes = graph->nodeList();
    for (auto &node: nodes) {
        std::unordered_map<std::string, bool> visited;
        std::list<std::string> steps;
        DFSUtil(graph, node->name(), visited, steps);
        for (auto &v: nodes) {
            if (!visited[v->name()])
                return false;
        }
    }
    return true;
}

bool GraphUtils::isAllWeaklyConnected(const Graph *graph) {
    auto nodes = graph->nodeList();
    std::queue<std::string> q;
    std::unordered_map<std::string, bool> visited;
    q.push(nodes.front()->name());
    visited[nodes.front()->name()] = true;

    while (!q.empty()) {
        auto vname = q.front();
        q.pop();
        for (auto &adj: nodes) {
            if ((graph->hasEdge(vname, adj->name()) || graph->hasEdge(adj->name(), vname)) &&
                !visited[adj->name()]) {
                visited[adj->name()] = true;
                q.push(adj->name());
            }
        }
    }
    for (auto &&i : visited)
        if (!i.second)
            return false;
    return true;
}

std::string minDistance(std::unordered_map<std::string, int> &dist, std::unordered_map<std::string, bool> &sptSet) {
    int min = INT_MAX;
    std::string min_index;
    int n = dist.size();
    for (auto &it: dist)
        if (!sptSet[it.first] && it.second < min)
            min = it.second, min_index = it.first;
    return min_index;
}

std::list<std::string> GraphUtils::Dijkstra(const Graph *graph, const std::string &start, const std::string &goal) {
    if (!graph->hasNode(start) || !graph->hasNode(goal))
        return std::list<std::string>();
    auto nodes = graph->nodeList();
    std::unordered_map<std::string, int> dist;
    for (auto &node: nodes)
        dist[node->name()] = INT_MAX;

    std::unordered_map<std::string, bool> sptSet;
    std::unordered_map<std::string, std::string> parent;
    dist[start] = 0;
    for (int count = 0; count < graph->countNodes() - 1; count++) {
        auto uname = minDistance(dist, sptSet);
        sptSet[uname] = true;
        for (auto &v: nodes) {
            if (!sptSet[v->name()] && graph->hasEdge(uname, v->name()) && dist[uname] != INT_MAX &&
                dist[uname] + graph->weight(uname, v->name()) < dist[v->name()]) {
                dist[v->name()] = dist[uname] + graph->weight(uname, v->name());
                parent[v->name()] = uname;
            }
        }
    }
    std::list<std::string> path;
    std::cout << "Dijkstra: shortest path from " << start << " to " << goal << ": ";
    if (dist[goal] == INT_MAX) {
        std::cout << " not found!\n";
        return path;
    }
    auto curr = goal;
    while (!curr.empty()) {
        path.push_front(curr);
        curr = parent[curr];
    }
    for (auto &nodeName: path)
        std::cout << nodeName << " ";
    std::cout << " ------------ cost = " << dist[goal];
    return path;
}

#include <cmath>

int euclideanDist(QPointF p1, QPointF p2) {
    return (int) std::sqrt(std::pow(p1.x() - p2.x(), 2) +
                           std::pow(p1.y() - p2.y(), 2));
}

std::list<std::string> GraphUtils::AStar(const Graph *graph, std::string start, std::string goal) {
    if (!graph->hasNode(start) || !graph->hasNode(goal))
        return std::list<std::string>();
    auto nodes = graph->nodeList();
    std::unordered_map<std::string, int> dist;
    std::unordered_map<std::string, int> cost;
    for (auto &node: nodes) {
        dist[node->name()] = INT_MAX;
        cost[node->name()] = INT_MAX;
    }

    std::unordered_map<std::string, bool> sptSet;
    std::unordered_map<std::string, std::string> parent;
    dist[start] = 0;
    cost[start] = 0;
    for (int count = 0; count < graph->countNodes() - 1; count++) {
        auto uname = minDistance(dist, sptSet);
        sptSet[uname] = true;
        for (auto &v: nodes) {
            double h = graph->weight(uname, v->name()) +
                       euclideanDist(graph->node(v->name())->euclidePos(), graph->node(goal)->euclidePos());
            if (!sptSet[v->name()] && graph->hasEdge(uname, v->name()) && dist[uname] != INT_MAX &&
                dist[uname] + h < dist[v->name()]) {
                dist[v->name()] = dist[uname] + h;
                cost[v->name()] = cost[uname] + graph->weight(uname, v->name());
                parent[v->name()] = uname;
            }
        }
    }
    std::list<std::string> path;
    std::cout << "A-star: Shortest path from " << start << " to " << goal << ": ";
    if (cost[goal] == INT_MAX) {
        std::cout << " not found!\n";
        return path;
    }
    auto curr = goal;
    while (!curr.empty()) {
        path.push_front(curr);
        curr = parent[curr];
    }
    for (auto &nodeName: path)
        std::cout << nodeName << " ";
    std::cout << " ------------ cost = " << cost[goal];
    return path;
}

std::string minKey(std::unordered_map<std::string, int> &key, std::unordered_map<std::string, bool> &mstSet) {
    int min = INT_MAX;
    std::string min_index;
    for (auto &it: key) {
        if (!mstSet[it.first] && it.second < min) {
            min = it.second;
            min_index = it.first;
        }
    }
    return min_index;
}

std::list<std::pair<std::string, std::string>>
PrimUtil(const Graph *graph, const std::string &source, bool &full, int &cost) {
    std::list<std::pair<std::string, std::string>> result;
    if (!graph->hasNode(source)) return result;
    std::unordered_map<std::string, std::string> parent;
    std::unordered_map<std::string, int> key;
    auto nodes = graph->nodeList();
    for (auto &node: nodes)
        key[node->name()] = INT_MAX;
    std::unordered_map<std::string, bool> mstSet;

    key[source] = 0;
    parent[source] = "";
    cost = 0;
    for (int count = 0; count < graph->countNodes(); count++) {
        auto u = minKey(key, mstSet);
        mstSet[u] = true;
        for (auto &node: nodes) {
            auto v = node->name();
            if (!mstSet[v]
                && graph->hasEdge(u, v)
                && graph->weight(u, v) < key[v]) {
                key[v] = graph->weight(u, v);
                parent[v] = u;
                result.emplace_back(std::make_pair(u, v));
                cost += graph->weight(u, v);
            }
        }
    }
    full = true;
    if (!result.empty()) {
        for (auto node: nodes) {
            if (node->name() != source && parent[node->name()].empty())
                full = false;
        }
    } else
        full = false;
    return result;
}

void
printMST(const Graph &graph, const std::list<std::pair<std::string, std::string>> &result, const std::string &source,
         int cost) {
    if (result.empty()) {
        std::cout << "Not found minimum spanning tree" << (source.empty() ? " for the whole graph" : " from source = ")
                  << source << "\n";
        return;
    }
    std::cout << "Minimum spanning tree (source = " << source << "): " << std::endl;
    std::cout << "vertex \t parent \t cost:" << std::endl;

    for (const auto &it: result) {
        std::cout << it.second << " \t " << it.first << " \t "
                  << graph.weight(it.first, it.second) << std::endl;
    }
    std::cout << "total cost: " << cost << "\n";
}

std::list<std::pair<std::string, std::string>> GraphUtils::Prim(const Graph *graph, std::string source) {
    std::list<std::pair<std::string, std::string>> result;
    const auto nodes = graph->nodeList();
    bool full{};
    int min_cost = INT_MAX;
    if (source.empty()) {
        if (!isAllWeaklyConnected(graph)) {
            std::cout << "Minimum spanning tree: not found because the graph is not connected!";
            return result;
        }
        for (auto node: nodes) {
            int cost;
            auto res = PrimUtil(graph, node->name(), full, cost);
            if (full && cost < min_cost) {
                result = res;
                min_cost = cost;
                source = node->name();
            }
        }
        printMST(*graph, result, source, min_cost);
        return result;
    }
    result = PrimUtil(graph, source, full, min_cost);
    printMST(*graph, result, source, min_cost);
    return result;
}

void weaklyFillOrder(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                     std::stack<std::string> &stack) {
    visited[vname] = true;
    auto nodes = graph->nodeList();
    for (auto &node: nodes)
        if (!visited[node->name()] && (graph->hasEdge(vname, node->name()) ||
                                       graph->hasEdge(vname, node->name())))
            weaklyFillOrder(graph, node->name(), visited, stack);
    stack.push(vname);
}

void stronglyFillOrder(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                       std::stack<std::string> &stack) {
    visited[vname] = true;
    auto nodes = graph->nodeList();
    for (auto &node: nodes)
        if (!visited[node->name()] && graph->hasEdge(vname, node->name()))
            weaklyFillOrder(graph, node->name(), visited, stack);
    stack.push(vname);
}

std::list<std::list<std::string>> GraphUtils::connectedComponents(const Graph *graph) {
    std::list<std::list<std::string>> result;
    std::unordered_map<std::string, bool> visited;
    std::stack<std::string> stack;

    auto nodes = graph->nodeList();
    for (auto &node: nodes)
        if (!visited[node->name()])
            stronglyFillOrder(graph, node->name(), visited, stack);

    Graph gr = graph->transpose();
    visited.clear();

    while (!stack.empty()) {
        auto vname = stack.top();
        stack.pop();

        if (!visited[vname]) {
            std::list<std::string> steps;
            DFSUtil(&gr, vname, visited, steps);
            result.push_back(steps);
        }
    }
    return result;
}

std::list<std::list<std::string>> GraphUtils::weaklyConnectedComponents(const Graph *graph) {
    std::list<std::list<std::string>> result;
    std::unordered_map<std::string, bool> visited;
    auto nodes = graph->nodeList();
    for (auto &node: nodes) {
        if (!visited[node->name()]) {
            std::list<std::string> component;
            UndirectedDFSUtil(graph, node->name(), visited, component);
            result.push_back(component);
        }
    }
    return result;
}

void bridgeUtil(const Graph *graph, const std::string &uname,
                std::unordered_map<std::string, bool> &visited,
                std::unordered_map<std::string, int> &disc,
                std::unordered_map<std::string, int> &low,
                std::unordered_map<std::string, std::string> &parent,
                std::list<std::pair<std::string, std::string>> &res, int &time) {

    visited[uname] = true;
    disc[uname] = low[uname] = ++time;
    auto nodes = graph->nodeList();
    for (auto &v: nodes) {
        if (!visited[v->name()] && graph->hasEdge(uname, v->name())) {
            parent[v->name()] = uname;
            bridgeUtil(graph, v->name(), visited, disc, low, parent, res, time);
            low[uname] = std::min(low[uname], low[v->name()]);
            if (low[v->name()] > disc[uname]) {
                res.emplace_back(uname, v->name());
            }
        } else if (v->name() != parent[uname] && graph->hasEdge(uname, v->name()))
            low[uname] = std::min(low[uname], disc[v->name()]);
    }
}

std::list<std::pair<std::string, std::string>> GraphUtils::getBridges(const Graph *graph) {
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, int> disc;
    std::unordered_map<std::string, int> low;
    std::unordered_map<std::string, std::string> parent;
    std::list<std::pair<std::string, std::string>> result;

    int time = 0;
    auto nodes = graph->nodeList();
    for (auto &v: nodes) {
        if (!visited[v->name()])
            bridgeUtil(graph, v->name(), visited, disc, low, parent, result, time);
    }
    return result;
}

void APUtil(const Graph *graph, const std::string &uname,
            std::unordered_map<std::string, bool> &visited,
            std::unordered_map<std::string, int> &disc,
            std::unordered_map<std::string, int> &low,
            std::unordered_map<std::string, std::string> &parent,
            std::list<std::string> &ap) {

    static int time = 0;
    int children = 0;
    visited[uname] = true;

    disc[uname] = low[uname] = ++time;

    for (auto &v: graph->nodeList()) {
        if (graph->hasEdge(uname, v->name())) {
            if (!visited[v->name()]) {
                children++;
                parent[v->name()] = uname;
                APUtil(graph, v->name(), visited, disc, low, parent, ap);

                low[uname] = std::min(low[uname], low[v->name()]);
                if (parent[uname].empty() && children > 1)
                    ap.push_front(uname);

                if (!parent[uname].empty() && low[v->name()] >= disc[uname])
                    ap.push_front(uname);
            } else if (v->name() != parent[uname])
                low[uname] = std::min(low[uname], disc[v->name()]);
        }
    }
}

std::list<std::string> GraphUtils::getArticulationNodes(const Graph *graph) {
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, int> disc;
    std::unordered_map<std::string, int> low;
    std::unordered_map<std::string, std::string> parent;
    std::list<std::string> ap;

    for (auto &node: graph->nodeList())
        if (!visited[node->name()])
            APUtil(graph, node->name(), visited, disc, low, parent, ap);
    return ap;
}

std::list<std::string> GraphUtils::displayArticulationNodes(const Graph *graph) {

    std::list<std::string> nodes = getArticulationNodes(graph);
    std::cout << "All articulation nodes: ";
    if (nodes.empty()) {
        std::cout << "not found!\n";
        return nodes;
    }
    for (auto &node: nodes)
        std::cout << node << " ";
    std::cout << "\n";
    return nodes;
}

std::list<std::pair<std::string, std::string>> GraphUtils::displayBridges(const Graph *graph) {
    std::list<std::pair<std::string, std::string>> bridges = getBridges(graph);
    std::cout << "Number of bridges: " << bridges.size() << "\n";
    for (const auto &b: bridges)
        std::cout << b.first << " " << b.second << "\n";
    return bridges;
}

std::list<std::list<std::string>> GraphUtils::displayConnectedComponents(const Graph *graph, bool strong) {
    auto nodes = graph->nodeList();
    std::list<std::list<std::string>> result;
    if (strong)
        result = connectedComponents(graph);
    else
        result = weaklyConnectedComponents(graph);
    std::cout << "Number of " << (strong ? (graph->isDirected() ? "strongly " : "") : "weakly ")
              << "connected components: " << result.size() << "\n";
    for (const auto &ri: result) {
        for (const auto &si: ri)
            std::cout << si << " ";
        std::cout << "\n";
    }
    return result;
}

bool isSafe(const Graph *graph, const std::string &vname,
            std::vector<std::string> &path, int pos) {
    if (!graph->hasEdge(path[pos - 1], vname))
        return false;
    for (int i = 0; i < pos; ++i)
        if (path[i] == vname)
            return false;
    return true;
}

bool hamCycleUtil(const Graph *graph, std::vector<std::string> &path, int pos) {
    int n = graph->countNodes();
    if (pos == n)
        return graph->hasEdge(path[pos - 1], path[0]);

    for (auto &v: graph->nodeList()) {
        if (v->name() != path[0] && isSafe(graph, v->name(), path, pos)) {
            path[pos] = v->name();
            if (hamCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = "";
        }
    }
    return false;
}

std::list<std::string> GraphUtils::getHamiltonianCircuit(const Graph *graph, std::string source) {
    auto nodes = graph->nodeList();
    if (source.empty())
        source = nodes.front()->name();
    std::vector<std::string> path(graph->countNodes(), "");
    std::list<std::string> result;
    path[0] = source;
    if (!hamCycleUtil(graph, path, 1))
        return result;
    for (int i = 0; i < graph->countNodes(); ++i)
        result.push_back(path[i]);
    result.push_back(path[0]);
    return result;
}

std::list<std::list<std::string>> GraphUtils::displayAllHamiltonianCircuits(const Graph *graph) {
    std::list<std::list<std::string>> result;
    if (graph->countNodes() < 3) {
        std::cout << "Hamiltonian Circuit not found: ";
        std::cout << "|V| = " << graph->countNodes() << " < 3\n";
        return result;
    }
    auto nodes = graph->nodeList();
    for (auto &source: nodes) {
        auto cycle = getHamiltonianCircuit(graph, source->name());
        if (cycle.empty())
            continue;
        else
            result.push_back(cycle);

        std::cout << "Hamiltonian Circuit (source = " << source->name() << "): ";
        for (auto &node: cycle)
            std::cout << node << " ";
        std::cout << "\n";
    }
    if (result.empty())
        std::cout << "Not found any Hamiltonian cycle";
    return result;
}

bool isBridge(Graph graph, const std::string &uname, const std::string &vname) {
    if (uname == vname)
        return false;
    std::unordered_map<std::string, bool> visited;
    int count1 = DFSCount(graph, uname, visited);
    graph.removeEdge(uname, vname);
    int count2 = DFSCount(graph, vname, visited);
    return count1 <= count2;
}

std::list<std::string> GraphUtils::Hierholzer(Graph &graph, const std::string &source) {
    std::list<std::string> result;
    std::stack<std::string> curr_path;
    std::vector<std::string> cycle;
    auto curr_node = source;
    curr_path.push(source);
    while (!curr_path.empty()) {
        int degree = graph.isDirected() ? graph.node(curr_node)->negDegree() : graph.node(curr_node)->undirDegree();
        if (degree) {
            curr_path.push(curr_node);
            std::string next_node;
            for (auto v: graph.nodeList()) {
                if (graph.hasEdge(curr_node, v->name())) {
                    next_node = v->name();
                    break;
                }
            }
            graph.removeEdge(curr_node, next_node);
            curr_node = next_node;
        } else {
            cycle.push_back(curr_node);
            curr_node = curr_path.top();
            curr_path.pop();
        }
    }
    for (int i = (int) cycle.size() - 1; i >= 0; --i)
        result.push_back(cycle[i]);
    return result;
}

std::list<std::string> GraphUtils::getEulerianCircuit(const Graph *_graph, std::string source) {
    std::list<std::string> result;
    Graph graph(*_graph);
    if (source.empty())
        source = graph.nodeList().front()->name();
    if (!graph.hasNode(source))
        return result;
    result = Hierholzer(graph, source);
    return result;
}

std::list<std::list<std::string>>
GraphUtils::displayAllEulerianCircuits(const Graph *graph) {
    std::list<std::list<std::string>> result;
    if (!isAllConnected(graph)) {
        std::cout << "Eulerian Circuit not found because the graph is not connected\n";
        return result;
    }
    for (auto &node: graph->nodeList()) {
        if (graph->isDirected() && node->negDegree() != node->posDegree()) {
            std::cout << "Eulerian Circuit not found because Node " << node->name() << " has deg+ != deg-\n";
            return result;
        } else if (graph->isUndirected() && node->undirDegree() % 2 != 0) {
            std::cout << "Eulerian Circuit not found because degree of Node " << node->name() << " is odd\n";
            return result;
        }
    }
    for (auto &node: graph->nodeList()) {
        auto cycle = getEulerianCircuit(graph, node->name());
        if (!cycle.empty()) {
            std::cout << "Euler Circuit (source = " << node->name() << "): ";
            result.emplace_back(cycle);
            while (!cycle.empty()) {
                std::cout << cycle.front() << " ";
                cycle.pop_front();
            }
            std::cout << "\n";
        }
    }
    return result;
}

void topoSortUtil(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                  std::stack<std::string> &stack) {
    visited[vname] = true;
    for (auto &node: graph->nodeList())
        if (graph->hasEdge(vname, node->name()) && !visited[node->name()])
            topoSortUtil(graph, node->name(), visited, stack);
    stack.push(vname);
}

bool GraphUtils::isCycle(const Graph *graph) {
    std::queue<std::string> q;
    std::unordered_map<std::string, int> in_degree;
    for (auto node: graph->nodeList()) {
        in_degree[node->name()] = node->posDegree();
        if (in_degree[node->name()] == 0)
            q.push(node->name());
    }
    int cnt = 0;
    std::vector<std::string> top_order;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        top_order.push_back(u);
        for (auto v: graph->nodeList()) {
            if (--in_degree[v->name()] == 0)
                q.push(v->name());
            cnt++;
        }
    }
    return (cnt != graph->countNodes());
}

std::list<std::string> GraphUtils::getTopoSortResult(const Graph *graph) {
    if (!(graph->isDirected() && isCycle(graph))) {
        std::cout << "The graph is not DAG\n";
        return std::list<std::string>();
    }
    std::unordered_map<std::string, bool> visited;
    std::stack<std::string> stack;
    for (auto &node: graph->nodeList())
        if (!visited[node->name()])
            topoSortUtil(graph, node->name(), visited, stack);

    std::list<std::string> result;
    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }
    return result;
}

std::list<std::string> GraphUtils::displayTopoSort(const Graph *graph) {
    std::list<std::string> topo_sorted;
    if (graph->isDirected()) {
        topo_sorted = getTopoSortResult(graph);
        std::cout << "Topo sorted: ";
        if (topo_sorted.empty()) {
            std::cout << "not found!\n";
            return topo_sorted;
        }
        for (const auto &v: topo_sorted)
            std::cout << v << " ";
        std::cout << "\n";
    }
    return topo_sorted;
}

std::list<std::pair<std::string, int>> GraphUtils::getColoringResult(const Graph *graph, std::string source) {
    std::list<std::pair<std::string, int>> res_list;
    if (graph->isDirected())
        return res_list;

    auto nodeList = graph->nodeList();
    auto nodes = std::vector<Node *>(nodeList.begin(), nodeList.end());
    std::sort(nodes.begin(), nodes.end(), 
        [](auto const &u, auto const &v) {
            return u->undirDegree() > v->undirDegree(); 
    });
    std::unordered_map<std::string, int> colors;
    for (auto &node: nodes) {
        colors[node->name()] = -1;
    }
    colors[nodes.front()->name()] = 0;
    for (int i = 1; i < nodes.size(); ++i) {
        std::vector<int> usedColors(nodes.size(), false);
        for (auto& p: graph->edgeSet()) {
            auto u = p.first.first;
            auto v = p.first.second;
            if (v->name() == nodes[i]->name()) {
                std::swap(u, v);
            }
            if (u->name() == nodes[i]->name() && colors[v->name()] != -1) {
                usedColors[colors[v->name()]] = true;
            }
        }
        int v_color;
        for (v_color = 0; v_color < nodes.size(); ++ v_color) {
            if (!usedColors[v_color]) {
                break;
            }
        }
        colors[nodes[i]->name()] = v_color;
    }
    for (auto &node: nodeList) {
        res_list.push_back({node->name(), colors[node->name()]});
    }
    return res_list;
}

std::list<std::pair<std::string, std::string>> GraphUtils::displayColoring(const Graph *graph, std::string source) {
    if (graph->isDirected())
        return std::list<std::pair<std::string, std::string>>();
    auto result = getColoringResult(graph, std::move(source));
    std::list<std::pair<std::string, std::string>> resultToSent;
    std::cout << "Coloring of the graph: " << std::endl;
    for (auto &it: result) {
        std::cout << "Node " << it.first << " ---> Color " << it.second << std::endl;
        resultToSent.emplace_back(it.first, std::to_string(it.second));
    }
    return resultToSent;
}

void DFSCycle(const Graph *graph, const std::string &uname, const std::string &pname,
              std::unordered_map<std::string, int> &color,
              std::unordered_map<std::string, int> &mark, std::unordered_map<std::string, std::string> &parent,
              int &cycle_number) {
    if (color[uname] == 2)
        return;
    if (color[uname] == 1) {
        cycle_number++;
        auto cur = pname;
        mark[cur] = cycle_number;
        while (cur != uname) {
            cur = parent[cur];
            mark[cur] = cycle_number;
        }
        return;
    }
    parent[uname] = pname;
    color[uname] = 1;
    for (auto v: graph->nodeList()) {
        if (graph->hasEdge(uname, v->name())) {
            if (v->name() == parent[uname])
                continue;
            DFSCycle(graph, v->name(), uname, color, mark, parent, cycle_number);
        }
    }
    color[uname] = 2;
}

std::list<std::list<std::string>> GraphUtils::displayAllCycles(const Graph *graph) {
    return Gotlieb(graph);
}

std::list<std::pair<std::string, std::string>>
GraphUtils::spanningTreeBFS(const Graph *graph, const std::string &source) {
    std::list<std::pair<std::string, std::string>> result;
    if (!graph->hasNode(source))
        return result;
    if (!isAllConnected(graph)) {
        std::cout << "The graph must be " << (graph->isDirected() ? "strongly " : "") << "connected";
        return result;
    }
    std::unordered_map<std::string, bool> in_unprocessed;
    std::unordered_map<std::string, bool> in_result;
    std::list<std::string> unprocessed_list;
    unprocessed_list.push_back(source);
    in_result[source] = true;
    in_unprocessed[source] = true;
    int cost = 0;
    std::cout << "Minimum spanning tree (source = " << source << "): " << std::endl;
    std::cout << "vertex \t parent \t cost:" << std::endl;
    while (!unprocessed_list.empty()) {
        auto uname = unprocessed_list.front();
        unprocessed_list.pop_front();
        in_unprocessed[uname] = false;
        for (auto v: graph->nodeList()) {
            if (graph->hasEdge(uname, v->name()) && !in_unprocessed[v->name()] && !in_result[v->name()]) {
                unprocessed_list.push_back(v->name());
                result.emplace_back(uname, v->name());
                in_unprocessed[v->name()] = true;
                in_result[v->name()] = true;
                std::cout << v->name() << "\t" << uname << "\t" << graph->weight(uname, v->name()) << std::endl;
                cost += graph->weight(uname, v->name());
            }
        }
    }
    std::cout << "total cost: " << cost << std::endl;
    return result;
}

void STDFSUtil(const Graph *graph, const std::string &uname, std::unordered_map<std::string, bool> &in_tree,
               std::list<std::pair<std::string, std::string>> &result, int &cost) {
    for (auto v: graph->nodeList()) {
        if (graph->hasEdge(uname, v->name()) && !in_tree[v->name()]) {
            in_tree[v->name()] = true;
            result.emplace_back(uname, v->name());
            std::cout << v->name() << "\t" << uname << "\t" << graph->weight(uname, v->name()) << std::endl;
            cost += graph->weight(uname, v->name());
            STDFSUtil(graph, v->name(), in_tree, result, cost);
        }
    }
}

std::list<std::pair<std::string, std::string>>
GraphUtils::spanningTreeDFS(const Graph *graph, const std::string &source) {
    std::list<std::pair<std::string, std::string>> result;
    if (!graph->hasNode(source))
        return result;
    if (!isAllConnected(graph)) {
        std::cout << "The graph must be " << (graph->isDirected() ? "strongly " : "") << "connected";
        return result;
    }
    std::unordered_map<std::string, bool> in_tree;
    in_tree[source] = true;
    int cost = 0;
    std::cout << "Minimum spanning tree (source = " << source << "): " << std::endl;
    std::cout << "vertex \t parent \t cost:" << std::endl;
    STDFSUtil(graph, source, in_tree, result, cost);
    std::cout << "total cost: " << cost << std::endl;
    return result;
}

void
DFSCheckCycle(std::vector<std::vector<int>> &adjMat, int u, int par, std::vector<bool> &visited, std::vector<int> &parents,
              int source, std::list<int> &foundCycle) {
    if (visited[u]) {
        if (u == source) {
            // cycle found
            parents[u] = par;
            while (true) {
                foundCycle.push_back(u);
                u = parents[u];
                if (u == source) {
                    foundCycle.push_back(u);
                    break;
                }
            }
        }
        return;
    }
    visited[u] = true;
    parents[u] = par;
    for (int v = 0; v < adjMat.size(); ++v) {
        if (adjMat[u][v] == 1 && v != parents[u]) {
            DFSCheckCycle(adjMat, v, u, visited, parents, source, foundCycle);
        }
    }
}

std::list<std::list<std::string>> GraphUtils::Gotlieb(const Graph *graph) {
    std::list<std::list<std::string>> result;
    auto temp = graph->adjMatrix();
    auto orgAdjMat = temp.mat();
    const auto &nodes = temp.nodes();
    int nodeCount = orgAdjMat.size();

    // BLOCK 1: Initialize adjacency matrix for spanning tree
    std::vector<std::vector<int>> treeAdjMat(nodeCount, std::vector<int>(nodeCount, 0));
    for (int i = 0; i < nodeCount; ++i)
        for (int j = i; j < nodeCount; ++j)
            if (orgAdjMat[i][j] == 1) {
                treeAdjMat[i][j] = 1;
                treeAdjMat[j][i] = 1;
                break;
            }
    // BLOCK 2: Find all connected components
    /* Example: C = [ [ 1 1 1 0 0 1 ],
     *                [ 0 0 0 1 0 0 ],
     *                [ 0 0 0 0 1 0 ] ] */
    std::vector<std::vector<int>> connComponents;
    std::vector<bool> visited(nodeCount, false);
    for (int u = 0; u < nodeCount; ++u) {
        if (visited[u])
            continue;
        std::vector<int> component(nodeCount, 0);
        std::stack<int> s;
        s.push(u);
        while (!s.empty()) {
            int v = s.top();
            visited[v] = true;
            component[v] = 1;
            s.pop();
            for (int w = 0; w < nodeCount; w++)
                if (treeAdjMat[v][w] && !visited[w])
                    s.push(w);
        }
        connComponents.push_back(component);
    }
    // So far, we have constructed a spanning tree. Now let focus on finding cycle bases
    // BLOCK 3: Here the connected components are amalgamated by adding
    // appropriate edges to the adjacency matrix B (treeAdjMat)
    // Example: edges (2,5) and (2,6) are added back to B
    std::unordered_map<int, bool> checked;
    for (auto &cmpt : connComponents)
        for (int j = 0; j < nodeCount; ++j)
            if (cmpt[j] == 1)
                for (int k = 0; k < nodeCount; k++)
                    if (orgAdjMat[j][k] == 1 && cmpt[k] == 0 && !checked[k]) {
                        treeAdjMat[k][j] = 1;
                        treeAdjMat[j][k] = 1;
                        checked[k] = true;
                    }
    // BLOCK 4
    // Collect all edges eliminated from the original adjacency matrix to build the spanning tree matrix
    std::list<std::pair<int, int>> eliminatedEdges;
    for (int i = 0; i < nodeCount; ++i)
        for (int j = i; j < nodeCount; ++j)
            if (treeAdjMat[i][j] != orgAdjMat[i][j])
                eliminatedEdges.emplace_back(i, j);
    // FINAL: Iterate through each eliminated edge, try adding it into the matrix B (treeAdjMat)
    // Then using DFS to check the cycle, the source node is the first node of the edge
    for (auto edge: eliminatedEdges) {
        visited = std::vector<bool>(nodeCount, false);
        std::vector<int> parents(nodeCount, -1);
        std::list<int> foundCycle;
        treeAdjMat[edge.first][edge.second] = treeAdjMat[edge.second][edge.first] = 1;
        DFSCheckCycle(treeAdjMat, edge.first, -1, visited, parents, edge.first, foundCycle);
        treeAdjMat[edge.first][edge.second] = treeAdjMat[edge.second][edge.first] = 0;
        if (!foundCycle.empty()) {
            std::cout << "Found cycle: ";
            std::list<std::string> cycleWithName;
            for (auto node: foundCycle) {
                std::cout << nodes[node]->name() << " ";
                cycleWithName.push_back(nodes[node]->name());
            }
            std::cout << std::endl;
            result.push_back(cycleWithName);
        }
    }
    return result;
}
