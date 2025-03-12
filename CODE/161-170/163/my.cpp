#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
struct Edge {
    int to;
    int weight;
};

const int INF = std::numeric_limits<int>::max();

void dijkstra(const std::vector<std::vector<Edge>>& graph, int source_index,
              int n, std::vector<int>& dist) {
    dist.assign(n + 1, INF);
    dist[source_index] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        pq;
    pq.emplace(0, source_index);

    while (!pq.empty()) {
        auto [d, u] = pq.top();  // u:index
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto& edge : graph[u]) {
            int v = edge.to, w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

bool is_valid_dijkstra_sequence(const std::vector<int>& sequence,
                                const std::vector<int>& dist) {
    std::unordered_set<int> visited;
    int n = sequence.size();
    for (int i = 0; i < n; i++) {
        int u = sequence[i];
        visited.insert(u);

        for (int v = 1; v <= n; v++) {
            if (!visited.count(v) && dist[v] < dist[u]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int Nv, Ne;
    std::cin >> Nv >> Ne;
    std::vector<std::vector<Edge>> graph(Nv + 1);

    for (int i = 0; i < Ne; i++) {
        int node1, node2, dist;
        std::cin >> node1 >> node2 >> dist;
        graph[node1].push_back({node2, dist});
        graph[node2].push_back({node1, dist});
    }

    int query_num;
    std::cin >> query_num;
    while (query_num--) {
        std::vector<int> sequence(Nv);
        for (int i = 0; i < Nv; i++) {
            std::cin >> sequence[i];
        }
        int source_index = sequence[0];
        std::vector<int> dist;
        dijkstra(graph, source_index, Nv, dist);
        std::cout << (is_valid_dijkstra_sequence(sequence, dist) ? "Yes" : "No")
                  << std::endl;
    }
}