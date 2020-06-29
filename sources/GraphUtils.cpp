#include "headers/GraphUtils.h"
#include <unordered_map>
#include <utility>
#include <QDebug>
#include <QString>

std::list<std::pair<std::string, std::string>> GraphUtils::BFSToDemo(const Graph *graph, const std::string &source) {
    std::list<std::pair<std::string, std::string>> result;
    if (!graph->hasNode(source)) return result;

    auto nodes = graph->nodeList();
    std::list<std::string> steps;
    std::queue<std::string> q;
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, std::string> parent;
    q.push(source);
    visited[source] = true;
    std::cout << "BFS (source = " << source << "): ";

    while (!q.empty()) {
        auto vname = q.front();
        steps.push_back(vname);
        std::cout << vname << " ";
        result.emplace_back(parent[steps.back()], steps.back());
        q.pop();

        for (auto &adj : nodes) {
            if (graph->hasArc(vname, adj->name()) && !visited[adj->name()]) {
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
    std::list<std::string> steps;
    std::stack<std::string> s;
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, std::string> parent;
    s.push(source);
    visited[source] = true;

    std::cout << "DFS (source = " << graph->node(source)->name() << "): ";
    while (!s.empty()) {
        auto vname = s.top();
        std::cout << graph->node(vname)->name() << " ";
        steps.push_back(vname);
        result.emplace_back(parent[steps.back()], steps.back());
        s.pop();

        for (auto &adj: nodes) {
            if (graph->hasArc(vname, adj->name()) && !visited[adj->name()]) {
                visited[adj->name()] = true;
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
            if (graph->hasArc(vname, adj->name()) && !visited[adj->name()]) {
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
        if (graph->hasArc(vname, adj->name()) && !visited[adj->name()])
            DFSUtil(graph, adj->name(), visited, steps);
    }
}

void UndirectedDFSUtil(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                       std::list<std::string> &steps) {
    visited[vname] = true;
    steps.push_back(vname);
    for (auto &adj: graph->nodeList()) {
        if ((graph->hasArc(vname, adj->name()) || graph->hasArc(adj->name(), vname)) && !visited[adj->name()])
            UndirectedDFSUtil(graph, adj->name(), visited, steps);
    }
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

bool GraphUtils::isAllStronglyConnected(const Graph *graph) {
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
            if ((graph->hasArc(vname, adj->name()) || graph->hasArc(adj->name(), vname)) &&
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
            if (!sptSet[v->name()] && graph->hasArc(uname, v->name()) && dist[uname] != INT_MAX &&
                dist[uname] + graph->weight(uname, v->name()) < dist[v->name()]) {
                dist[v->name()] = dist[uname] + graph->weight(uname, v->name());
                parent[v->name()] = uname;
            }
        }
    }
    std::list<std::string> path;
    std::cout << "Shortest path from " << start << " to " << goal << ": ";
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

std::list<std::pair<std::string, std::string>> GraphUtils::Prim(const Graph *graph, std::string source) {
    const auto nodes = graph->nodeList();
    if (source.empty())
        source = nodes.front()->name();
    std::list<std::pair<std::string, std::string>> result;
    if (!graph->hasNode(source)) return result;
    if (!isAllWeaklyConnected(graph)) {
        std::cout << "Minimum spanning tree: not found because the graph is not weakly connected!";
        return result;
    }
    std::unordered_map<std::string, std::string> parent;
    std::unordered_map<std::string, int> key;
    for (auto &node: nodes)
        key[node->name()] = INT_MAX;
    std::unordered_map<std::string, bool> mstSet;

    key[source] = 0;
    parent[source] = "";
    for (int count = 0; count < graph->countNodes(); count++) {
        auto u = minKey(key, mstSet);
        mstSet[u] = true;
        for (auto &node: nodes) {
            auto v = node->name();
            if (!mstSet[v]
                && graph->hasArc(u, v)
                && graph->weight(u, v) < key[v]) {
                key[v] = graph->weight(u, v);
                parent[v] = u;
            }
        }
    }
    int cost = 0;
    std::cout << "Minimum panning tree (source = " << source << "): " << std::endl;
    std::cout << "vertex\tparent\tcost:" << std::endl;
    for (auto &node: nodes) {
        if (node->name() != source) {
            if (graph->hasArc(parent[node->name()], node->name())) {
                result.emplace_back(std::make_pair(parent[node->name()], node->name()));
                std::cout << node->name() << "\t" << parent[node->name()] << "\t"
                          << graph->weight(parent[node->name()], node->name()) << std::endl;
                cost += graph->weight(parent[node->name()], node->name());
            }
        }
    }
    if (!result.empty())
        std::cout << "total cost: " << cost;
    else
        std::cout << "not found";
    std::cout << "\n";
    return result;
}

void weaklyFillOrder(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                     std::stack<std::string> &stack) {
    visited[vname] = true;
    auto nodes = graph->nodeList();
    for (auto &node: nodes)
        if (!visited[node->name()] && (graph->hasArc(vname, node->name()) ||
                                       graph->hasArc(vname, node->name())))
            weaklyFillOrder(graph, node->name(), visited, stack);
    stack.push(vname);
}

void stronglyFillOrder(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                       std::stack<std::string> &stack) {
    visited[vname] = true;
    auto nodes = graph->nodeList();
    for (auto &node: nodes)
        if (!visited[node->name()] && graph->hasArc(vname, node->name()))
            weaklyFillOrder(graph, node->name(), visited, stack);
    stack.push(vname);
}

std::list<std::list<std::string>> GraphUtils::stronglyConnectedComponents(const Graph *graph) {
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
        if (!visited[v->name()] && graph->hasArc(uname, v->name())) {
            parent[v->name()] = uname;
            bridgeUtil(graph, v->name(), visited, disc, low, parent, res, time);
            low[uname] = std::min(low[uname], low[v->name()]);
            if (low[v->name()] > disc[uname]) {
                res.emplace_back(uname, v->name());
            }
        } else if (v->name() != parent[uname] && graph->hasArc(uname, v->name()))
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
        if (graph->hasArc(uname, v->name())) {
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
        std::cout << " - " << b.first << " " << b.second << "\n";
    return bridges;
}

std::list<std::list<std::string>> GraphUtils::displayConnectedComponents(const Graph *graph, bool strong) {
    auto nodes = graph->nodeList();
    std::list<std::list<std::string>> result;
    if (strong)
        result = stronglyConnectedComponents(graph);
    else
        result = weaklyConnectedComponents(graph);
    std::cout << "Number of " << (strong ? "strongly" : "weakly") << " connected components: " << result.size() << "\n";
    for (const auto &ri: result) {
        for (const auto &si: ri)
            std::cout << si << " ";
        std::cout << "\n";
    }
    return result;
}

bool isSafe(const Graph *graph, const std::string &vname,
            std::vector<std::string> &path, int pos) {
    if (!graph->hasArc(path[pos - 1], vname))
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == vname)
            return false;
    return true;
}

bool hamCycleUtil(const Graph *graph, std::vector<std::string> &path, int pos) {
    int n = graph->countNodes();
    if (pos == n)
        return graph->hasArc(path[pos - 1], path[0]);

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

std::list<std::string> GraphUtils::getHamiltonianCycle(const Graph *graph, std::string source) {
    auto nodes = graph->nodeList();
    if (source.empty())
        source = nodes.front()->name();
    std::vector<std::string> path(graph->countNodes(), "");
    std::list<std::string> result;
    path[0] = source;
    if (!hamCycleUtil(graph, path, 1))
        return result;
    for (int i = 0; i < graph->countNodes(); i++)
        result.push_back(path[i]);
    result.push_back(path[0]);
    return result;
}

std::list<std::list<std::string>> GraphUtils::displayHamiltonianCycle(const Graph *graph) {

    std::list<std::list<std::string>> result;
    if (graph->countNodes() < 3) {
        std::cout << "Hamiltonian Cycle not found: ";
        std::cout << "|V| = " << graph->countNodes() << " < 3\n";
        return result;
    }
    auto nodes = graph->nodeList();
    for (auto &node: nodes)
        if (node->degree() < graph->countNodes() / 2) {
            std::cout << "Hamiltonian Cycle not found: ";
            std::cout << "deg(" << node->name() << ") = " << node->degree() << " < " << graph->countNodes()
                      << "/2\n";
            return result;
        }

    for (auto &source: nodes) {
        std::cout << "Hamiltonian Cycle (source = " << source->name() << "): ";
        auto cycle = getHamiltonianCycle(graph, source->name());
        if (cycle.empty())
            std::cout << "not found!";
        else
            result.push_back(cycle);

        for (auto &node: cycle)
            std::cout << node << " ";
        std::cout << "\n";
    }
    return result;
}

std::list<std::string> GraphUtils::getEulerianCircuit(const Graph *_graph, std::string source) {
    auto graph = *_graph;
    auto nodes = graph.nodeList();
    if (source.empty())
        source = nodes.front()->name();
    std::list<std::string> cycle;
    std::stack<std::string> s;
    s.push(source);
    while (!s.empty()) {
        auto vname = s.top();
        if (graph.node(vname)->degree() > 0) {
            for (auto &adj: graph.nodeList()) {
                if (graph.hasArc(vname, adj->name())) {
                    s.push(adj->name());
                    graph.removeArc(vname, adj->name());
                    break;
                }
            }
        } else {
            cycle.push_front(vname);
            s.pop();
        }
    }
    return cycle;
}

std::list<std::list<std::string>> GraphUtils::displayEulerianCircuit(const Graph *graph) {
    std::list<std::list<std::string>> result;
    if (!isAllStronglyConnected(graph)) {
        std::cout << "Eulerian Circuit not found because the graph is not strongly connected\n";
        return result;
    }
    auto nodes = graph->nodeList();
    for (auto &node: nodes) {
        if (node->negativeDegree() != node->positiveDegree()) {
            std::cout << "Eulerian Circuit not found because Node " << node->name() << " has deg+ != deg-\n";
            return result;
        }
    }

    for (auto &node: nodes) {
        std::list<std::string> cycle = getEulerianCircuit(graph, node->name());
        std::cout << "Euler Circuit (source = " << node->name() << "): ";
        if (cycle.empty())
            std::cout << "not found!\n";
        else
            result.push_back(cycle);
        for (auto &v: cycle)
            std::cout << v << " ";
        std::cout << "\n";
    }
    return result;
}

void topoSortUtil(const Graph *graph, const std::string &vname, std::unordered_map<std::string, bool> &visited,
                  std::stack<std::string> &stack) {
    visited[vname] = true;
    for (auto &node: graph->nodeList())
        if (graph->hasArc(vname, node->name()) && !visited[node->name()])
            topoSortUtil(graph, node->name(), visited, stack);
    stack.push(vname);
}

std::list<std::string> GraphUtils::getTopoSortResult(const Graph *graph) {
    if (!isAllWeaklyConnected(graph)) {
        std::cout << "The is not weakly connected\n";
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
    std::list<std::string> topo_sorted = getTopoSortResult(graph);
    std::cout << "Topo sorted: ";
    if (topo_sorted.empty()) {
        std::cout << "not found!\n";
        return topo_sorted;
    }
    for (const auto &v: topo_sorted)
        std::cout << v << " ";
    std::cout << "\n";
    return topo_sorted;
}

std::list<std::pair<std::string, int>> GraphUtils::getColoringResult(const Graph *graph, std::string source) {
    auto nodes = graph->nodeList();
    if (source.empty())
        source = nodes.front()->name();
    std::unordered_map<int, bool> available; // available colors
    std::unordered_map<std::string, int> result; // result: map of pairs { nodeName : _color }
    std::list<std::pair<std::string, int>> res_list;
    result[source] = 0;
    for (int i = 1; i < nodes.size(); i++) {
        auto v = nodes.front();
        for (int j = 0; j < nodes.size(); j++) {
            auto adj = nodes.front();
            if (graph->hasArc(v->name(), adj->name())) {
                if (result[adj->name()])
                    available[result[adj->name()]] = true;
            }
        }
        int cr;
        for (cr = 0; cr < graph->countNodes(); cr++)
            if (!available[cr])
                break;
        result[v->name()] = cr;
        for (auto &adj: nodes) {
            if (graph->hasArc(v->name(), adj->name())) {
                if (result[adj->name()] != -1)
                    available[result[adj->name()]] = false;
            }
        }
    }
    for (auto &node: nodes) // using for loop because it requires ordering from node 0th to node 0th and result map is unordered
        res_list.emplace_back(std::make_pair(
                node->name(),
                result[node->name()]));
    return res_list;
}

std::list<std::pair<std::string, std::string>> GraphUtils::displayColoring(const Graph *graph, std::string source) {
    auto result = getColoringResult(graph, std::move(source));
    std::list<std::pair<std::string, std::string>> resultToSent;
    std::cout << "Coloring of the graph: " << std::endl;
    for (auto &it: result) {
        std::cout << "Node " << it.first << " ---> Color " << it.second << std::endl;
        resultToSent.emplace_back(it.first, std::to_string(it.second));
    }
    return resultToSent;
}
