#include "headers/GraphUtils.h"

std::list<std::pair<int, int>> GraphUtils::BfsToDemo(const Graph &graph, int source) {
    std::list<std::pair<int, int>> res;
    if (!graph.hasThisNode(source)) return res;

    int n = graph.getNodeNum();
    std::list<int> steps;
    std::queue<int> q;
    std::vector<bool> visited(n, false);
    std::vector<int> parent(n, -1);
    q.push(source);
    visited[source] = true;
    std::cout << "BFS (source = " << graph.getNodeName(source) << "): ";

    while (!q.empty()) {
        int v = q.front();
        steps.push_back(v);
        std::cout << graph.getNodeName(v) << " ";
        res.emplace_back(parent[steps.back()], steps.back());
        q.pop();

        for (int adj = 0; adj < n; adj++) {
            if (graph.hasThisArc(v, adj) && !visited[adj]) {
                visited[adj] = true;
                q.push(adj);
                parent[adj] = v;
            }
        }
    }
    std::cout << "\n";
    return res;
}

std::list<std::pair<int, int>> GraphUtils::DfsToDemo(const Graph &graph, int source) {
    std::list<std::pair<int, int>> res;
    if (!graph.hasThisNode(source)) return res;

    int n = graph.getNodeNum();
    std::list<int> steps;
    std::stack<int> s;
    std::vector<bool> visited(n, false);
    std::vector<int> parent(n, -1);
    s.push(source);
    visited[source] = true;

    std::cout << "DFS (source = " << graph.getNodeName(source) << "): ";
    while (!s.empty()) {
        int v = s.top();
        std::cout << graph.getNodeName(v) << " ";
        steps.push_back(v);
        res.emplace_back(parent[steps.back()], steps.back());
        s.pop();

        for (int adj = 0; adj < n; adj++) {
            if (graph.hasThisArc(v, adj) && !visited[adj]) {
                visited[adj] = true;
                s.push(adj);
                parent[adj] = v;
            }
        }
    }
    std::cout << "\n";
    return res;
}

std::list<int> GraphUtils::BFS(const Graph &graph, int source) {

    std::list<int> steps;
    if (!graph.hasThisNode(source)) return steps;
    int n = graph.getNodeNum();

    std::queue<int> q;
    std::vector<bool> visited(n, false);
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int v = q.front();
        steps.push_back(v);
        q.pop();

        for (int adj = 0; adj < n; adj++) {
            if (graph.hasThisArc(v, adj) && !visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
    return steps;
}

void GraphUtils::DFSUtil(const Graph &graph, int v, std::vector<bool> &visited, std::list<int> &steps) {
    visited[v] = true;
    steps.push_back(v);
    for (int i = 0; i < graph.getNodeNum(); i++) {
        if (graph.hasThisArc(v, i) && !visited[i])
            DFSUtil(graph, i, visited, steps);
    }
}

void UndirectedDFSUtil(const Graph &graph, int v, std::vector<bool> &visited, std::list<int> &steps) {
    visited[v] = true;
    steps.push_back(v);
    for (int i = 0; i < graph.getNodeNum(); i++) {
        if ((graph.hasThisArc(v, i) || graph.hasThisArc(i, v)) && !visited[i])
            UndirectedDFSUtil(graph, i, visited, steps);
    }
}

std::list<int> GraphUtils::DFS(const Graph &graph, int source) {
    std::list<int> steps;
    if (!graph.hasThisNode(source)) return steps;
    std::vector<bool> visited(graph.getNodeNum(), false);
    DFSUtil(graph, source, visited, steps);
    return steps;
}

bool GraphUtils::isConnectedFromUtoV(const Graph &graph, int u, int v) {
    if (!graph.hasThisNode(u) || !graph.hasThisNode(v)) return false;
    std::vector<bool> visited(graph.getNodeNum(), false);
    std::list<int> steps;
    DFSUtil(graph, u, visited, steps);
    return !!visited[v];
}

bool GraphUtils::isAllStronglyConnected(const Graph &graph) {
    std::vector<bool> visited(graph.getNodeNum(), false);
    for (int u = 0; u < graph.getNodeNum(); u++) {
        visited = std::vector<bool>(graph.getNodeNum(), false);
        std::list<int> steps;
        DFSUtil(graph, u, visited, steps);
        for (int i = 0; i < graph.getNodeNum(); i++) {
            if (!visited[i])
                return false;
        }
    }
    return true;
}

bool GraphUtils::isAllWeaklyConnected(const Graph &graph) {

    int n = graph.getNodeNum();
    std::queue<int> q;
    std::vector<bool> visited(n, false);
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int adj = 0; adj < n; adj++) {
            if ((graph.hasThisArc(v, adj) || graph.hasThisArc(adj, v)) && !visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
    for (auto &&i : visited)
        if (i == false)
            return false;
    return true;
}

int minDistance(std::vector<int> &dist, std::vector<bool> &sptSet) {
    int min = INT_MAX, min_index;
    int n = dist.size();
    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] < min)
            min = dist[v], min_index = v;

    return min_index;
}

std::list<int> GraphUtils::Dijkstra(const Graph &graph, int start, int goal) {
    std::vector<int> dist(graph.getNodeNum(), INT_MAX);
    std::vector<bool> sptSet(graph.getNodeNum(), false);
    std::vector<int> parent(graph.getNodeNum(), -1);
    dist[start] = 0;
    for (int count = 0; count < graph.getNodeNum() - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < graph.getNodeNum(); v++) {
            if (!sptSet[v] && graph.hasThisArc(u, v) && dist[u] != INT_MAX &&
                dist[u] + graph.getArcWeight(u, v) < dist[v]) {
                dist[v] = dist[u] + graph.getArcWeight(u, v);
                parent[v] = u;
            }
        }
    }
    std::list<int> path;
    std::cout << "Shortest path from " << graph.getNodeName(start) << " to " << graph.getNodeName(goal) << ": ";
    if (dist[goal] == INT_MAX) {
        std::cout << " not found!\n";
        return path;
    }
    int curr = goal;
    while (curr != -1) {
        path.push_front(curr);
        curr = parent[curr];
    }
    for (auto itr = path.begin(); std::next(itr) != path.end(); itr++)
        std::cout << graph.getNodeName(*itr) << " -> ";
    std::cout << graph.getNodeName(goal) << ", cost = " << dist[goal];
    return path;
}


int minKey(std::vector<int> &key, std::vector<bool> &mstSet) {
    int min = INT_MAX, min_index;
    int n = key.size();
    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

std::list<std::pair<int, int>> GraphUtils::Prim(const Graph &graph, int source) {

    std::list<std::pair<int, int>> res;
    if (!graph.hasThisNode(source)) return res;
    if (!isAllWeaklyConnected(graph)) {
        std::cout << "Minimum spanning tree: not found because the graph is not weakly connected!";
        return res;
    }
    int n = graph.getNodeNum();
    std::vector<int> parent(n);
    std::vector<int> key(n, INT_MAX);
    std::vector<bool> mstSet(n, false);
    std::vector<std::vector<int>> adj_mat = graph.getAdjMatrix();

    key[source] = 0;
    parent[source] = -1;
    for (int count = 0; count < n; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v]
                && graph.hasThisArc(u, v)
                && adj_mat[u][v] < key[v]) {
                key[v] = adj_mat[u][v];
                parent[v] = u;
            }
        }
    }
    std::vector<Node> node_list = graph.getNodeList();
    int cost = 0;
    std::cout << "Minimum panning tree (source = " << node_list[source].getName() << "): " << std::endl;
    std::cout << "vertex\tparent\tcost:" << std::endl;
    for (int i = 0; i < n; i++) {
        if (i != source) {
            if (graph.hasThisArc(parent[i], i)) {
                res.emplace_back(parent[i], i);
                std::cout << node_list[i].getName() << "\t" << node_list[parent[i]].getName() << "\t"
                          << adj_mat[parent[i]][i] << std::endl;
                cost += adj_mat[parent[i]][i];
            }
        }
    }
    if (!res.empty())
        std::cout << "total cost: " << cost;
    else
        std::cout << "not found";
    std::cout << "\n";
    return res;
}

void weaklyFillOrder(Graph &graph, int v, std::vector<bool> &visited, std::stack<int> &stack) {
    visited[v] = true;
    for (int i = 0; i < graph.getNodeNum(); i++)
        if (!visited[i] && (graph.hasThisArc(v, i) || graph.hasThisArc(v, i)))
            weaklyFillOrder(graph, i, visited, stack);
    stack.push(v);
}

void stronglyFillOrder(const Graph &graph, int v, std::vector<bool> &visited, std::stack<int> &stack) {
    visited[v] = true;
    for (int i = 0; i < graph.getNodeNum(); i++)
        if (!visited[i] && graph.hasThisArc(v, i))
            stronglyFillOrder(graph, i, visited, stack);
    stack.push(v);
}

std::list<std::list<int>> GraphUtils::stronglyConnectedComponents(const Graph &graph) {
    std::list<std::list<int>> res;
    std::vector<bool> visited(graph.getNodeNum(), false);
    std::stack<int> stack;

    for (int i = 0; i < graph.getNodeNum(); i++)
        if (!visited[i])
            stronglyFillOrder(graph, i, visited, stack);

    Graph gr = graph.getTranspose();
    visited.clear();
    visited = std::vector<bool>(graph.getNodeNum(), false);

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (!visited[v]) {
            std::list<int> steps;
            DFSUtil(gr, v, visited, steps);
            res.push_back(steps);
        }
    }
    return res;
}

std::list<std::list<int>> GraphUtils::weaklyConnectedComponents(const Graph &graph) {
    std::list<std::list<int>> res;
    std::vector<bool> visited(graph.getNodeNum(), false);
    for (int v = 0; v < graph.getNodeNum(); v++) {
        if (!visited[v]) {
            std::list<int> component;
            UndirectedDFSUtil(graph, v, visited, component);
            res.push_back(component);
        }
    }
    return res;
}

void bridgeUtil(const Graph &graph, int u,
                std::vector<bool> &visited,
                std::vector<int> &disc,
                std::vector<int> &low,
                std::vector<int> &parent,
                std::list<std::pair<int, int>> &res, int &time) {

    visited[u] = true;
    disc[u] = low[u] = ++time;
    for (int v = 0; v < graph.getNodeNum(); v++) {
        if (!visited[v] && graph.hasThisArc(u, v)) {
            parent[v] = u;
            bridgeUtil(graph, v, visited, disc, low, parent, res, time);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > disc[u]) {
                res.emplace_back(u, v);
            }
        } else if (v != parent[u] && graph.hasThisArc(u, v))
            low[u] = std::min(low[u], disc[v]);
    }
}

std::list<std::pair<int, int>> GraphUtils::getBridges(const Graph &graph) {
    std::list<std::pair<int, int>> res;
    std::vector<bool> visited(graph.getNodeNum(), false);
    std::vector<int> disc(graph.getNodeNum());
    std::vector<int> low(graph.getNodeNum());
    std::vector<int> parent(graph.getNodeNum(), -1);

    int time = 0;
    for (int v = 0; v < graph.getNodeNum(); v++) {
        if (!visited[v])
            bridgeUtil(graph, v, visited, disc, low, parent, res, time);
    }
    return res;
}

void APUtil(const Graph &graph, int u,
            std::vector<bool> &visited,
            std::vector<int> &disc,
            std::vector<int> &low,
            std::vector<int> &parent,
            std::list<int> &ap) {

    static int time = 0;
    int children = 0;
    visited[u] = true;

    disc[u] = low[u] = ++time;

    for (int v = 0; v < graph.getNodeNum(); ++v) {
        if (graph.hasThisArc(u, v)) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                APUtil(graph, v, visited, disc, low, parent, ap);

                low[u] = std::min(low[u], low[v]);
                if (parent[u] == -1 && children > 1)
                    ap.push_front(u);

                if (parent[u] != -1 && low[v] >= disc[u])
                    ap.push_front(u);
            } else if (v != parent[u])
                low[u] = std::min(low[u], disc[v]);
        }
    }
}

std::list<int> GraphUtils::getArticulationNodes(const Graph &graph) {
    std::vector<bool> visited(graph.getNodeNum(), false);
    std::vector<int> disc(graph.getNodeNum());
    std::vector<int> low(graph.getNodeNum());
    std::vector<int> parent(graph.getNodeNum(), -1);
    std::list<int> ap;

    for (int i = 0; i < graph.getNodeNum(); i++)
        if (visited[i] == false)
            APUtil(graph, i, visited, disc, low, parent, ap);
    return ap;
}

std::list<int> GraphUtils::displayArticulationNodes(const Graph &graph) {
    std::list<int> nodes = getArticulationNodes(graph);
    std::cout << "All articulation nodes: ";
    if (nodes.empty()) {
        std::cout << "not found!\n";
        return nodes;
    }
    for (auto node: nodes)
        std::cout << graph.getNodeName(node) << " ";
    std::cout << "\n";
    return nodes;
}

std::list<std::pair<int, int>> GraphUtils::displayBridges(const Graph &graph) {
    std::list<std::pair<int, int>> bridges = getBridges(graph);
    std::cout << "Number of bridges: " << bridges.size() << "\n";
    for (auto b: bridges)
        std::cout << " - " << graph.getNodeName(b.first) << " " << graph.getNodeName(b.second) << "\n";
    return bridges;
}

std::list<std::list<int>> GraphUtils::displayConnectedComponents(const Graph &graph, bool strong) {
    std::vector<Node> node_list = graph.getNodeList();
    std::list<std::list<int>> res;
    if (strong)
        res = stronglyConnectedComponents(graph);
    else
        res = weaklyConnectedComponents(graph);

    std::cout << "Number of " << (strong ? "strongly" : "weakly") << " connected components: " << res.size() << "\n";

    for (const auto &ri: res) {
        std::cout << " - ";
        for (auto si: ri)
            std::cout << node_list[si].getName() << " ";
        std::cout << "\n";
    }
    return res;
}

bool isSafe(const Graph &graph, int v,
            std::vector<int> &path, int pos) {
    if (!graph.hasThisArc(path[pos - 1], v))
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamCycleUtil(const Graph &graph, std::vector<int> &path, int pos) {
    int V = graph.getNodeNum();
    if (pos == V)
        return graph.hasThisArc(path[pos - 1], path[0]);

    for (int v = 0; v < V; v++) {
        if (v != path[0] && isSafe(graph, v, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

std::list<int> GraphUtils::getHamiltonianCycle(const Graph &graph, int source) {

    std::vector<int> path(graph.getNodeNum(), -1);
    std::list<int> res;
    path[0] = source;
    if (!hamCycleUtil(graph, path, 1))
        return res;

    for (int i = 0; i < graph.getNodeNum(); i++)
        res.push_back(path[i]);
    res.push_back(path[0]);
    return res;
}

std::list<std::list<int>> GraphUtils::displayHamiltonianCycle(const Graph &graph) {

    std::list<std::list<int>> res;
    if (graph.getNodeNum() < 3) {
        std::cout << "Hamiltonian Cycle not found: ";
        std::cout << "|V| = " << graph.getNodeNum() << " < 3\n";
        return res;
    }
    for (Node &node: graph.getNodeList())
        if (node.getDeg() < graph.getNodeNum() / 2) {
            std::cout << "Hamiltonian Cycle not found: ";
            std::cout << "deg(" << node.getName() << ") = " << node.getDeg() << " < " << graph.getNodeNum() << "/2\n";
            return res;
        }

    for (int source = 0; source < graph.getNodeNum(); source++) {
        std::cout << "Hamiltonian Cycle (source = " << graph.getNodeName(source) << "): ";
        std::list<int> cycle = getHamiltonianCycle(graph, source);
        if (cycle.empty())
            std::cout << "not found!";
        else
            res.push_back(cycle);

        for (auto i: cycle)
            std::cout << graph.getNodeName(i) << " ";
        std::cout << "\n";
    }
    return res;
}

std::list<int> GraphUtils::getEulerianCircuit(Graph graph, int source) {
    std::list<int> cycle;
    std::stack<int> s;
    s.push(source);
    while (!s.empty()) {
        int v = s.top();
        Node *node_v = graph.getNode(v);
        if (node_v->getDeg() > 0) {
            for (int adj = 0; adj < graph.getNodeNum(); adj++) {
                if (graph.hasThisArc(v, adj)) {
                    s.push(adj);
                    graph.removeArc(v, adj);
                    break;
                }
            }
        } else {
            cycle.push_front(v);
            s.pop();
        }
    }
    return cycle;
}

std::list<std::list<int>> GraphUtils::displayEulerianCircuit(const Graph &graph) {
    std::list<std::list<int>> res;
    if (!isAllStronglyConnected(graph)) {
        std::cout << "Eulerian Circuit not found because the graph is not strongly connected\n";
        return res;
    }
    for (const Node &node: graph.getNodeList()) {
        if (node.getNegativeDeg() != node.getPositiveDeg()) {
            std::cout << "Eulerian Circuit not found because Node " << node.getName() << " has deg+ != deg-\n";
            return res;
        }
    }

    for (int source = 0; source < graph.getNodeNum(); source++) {
        std::list<int> cycle = getEulerianCircuit(graph, source);
        std::cout << "Euler Circuit (source = " << graph.getNodeName(source) << "): ";
        if (cycle.empty())
            std::cout << "not found!\n";
        else
            res.push_back(cycle);
        for (auto i: cycle)
            std::cout << graph.getNodeName(i) << " ";
        std::cout << "\n";
    }
    return res;
}

void topoSortUtil(const Graph &graph, int v, std::vector<bool> &visited, std::stack<int> &stack) {
    visited[v] = true;
    for (int i = 0; i < graph.getNodeNum(); i++)
        if (graph.hasThisArc(v, i) && !visited[i])
            topoSortUtil(graph, i, visited, stack);
    stack.push(v);
}

std::list<int> GraphUtils::getTopoSortResult(const Graph &graph) {
    if (!isAllWeaklyConnected(graph)) {
        std::cout << "The graph is not weakly connected\n";
        return std::list<int>();
    }
    std::vector<bool> visited(graph.getNodeNum(), false);
    std::stack<int> stack;
    for (int i = 0; i < graph.getNodeNum(); i++)
        if (!visited[i])
            topoSortUtil(graph, i, visited, stack);

    std::list<int> res;
    while (!stack.empty()) {
        res.push_back(stack.top());
        stack.pop();
    }
    return res;
}

std::list<int> GraphUtils::displayTopoSort(const Graph& graph) {
    std::list<int> topo_sorted = getTopoSortResult(graph);
    std::cout << "Topo sorted: ";
    if (topo_sorted.empty()) {
        std::cout << "not found!\n";
        return topo_sorted;
    }
    for (auto v: topo_sorted)
        std::cout << graph.getNodeName(v) << " ";
    std::cout << "\n";
    return topo_sorted;
}

std::list<int> GraphUtils::getColoringResult(const Graph& graph, int source) {
    std::vector<bool> available(graph.getNodeNum(), false);
    std::vector<int> res(graph.getNodeNum(), -1);
    res[source] = source;
    for (int v = 1; v < graph.getNodeNum(); v++) {
        for (int adj = 0; adj < graph.getNodeNum(); adj++) {
            if (graph.hasThisArc(v, adj)) {
                if (res[adj] != -1)
                    available[res[adj]] = true;
            }
        }

        int cr;
        for (cr = 0; cr < graph.getNodeNum(); cr++)
            if (available[cr] == false)
                break;

        res[v] = cr;
        for (int adj = 0; adj < graph.getNodeNum(); adj++) {
            if (graph.hasThisArc(v, adj)) {
                if (res[adj] != -1)
                    available[res[adj]] = false;
            }
        }
    }
    std::list<int> res_list;
    std::copy(res.begin(), res.end(), std::back_inserter(res_list));
    return res_list;
}

std::list<int> GraphUtils::displayColoring(const Graph& graph, int source) {
    std::list<int> res = getColoringResult(graph, source);
    std::cout << "Coloring of the graph: " << std::endl;
    int v = 0;
    for (auto color: res) {
        std::cout << "Node " << graph.getNodeName(v) << " ---> Color " << color << std::endl;
        v++;
    }
    return res;
}
