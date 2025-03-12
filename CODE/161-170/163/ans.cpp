#include <iostream>
#include <limits>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

struct Edge {
    int to, weight;
};

const int INF = numeric_limits<int>::max();

void dijkstra(int source, int n, const vector<vector<Edge>>& adj,
              vector<int>& dist) {
    dist.assign(n + 1, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to, w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

bool is_valid_dijkstra_sequence(const vector<int>& sequence,
                                const vector<int>& dist) {
    int n = sequence.size();
    unordered_set<int> visited;

    for (int i = 0; i < n; ++i) {
        int u = sequence[i];
        visited.insert(u);

        // 确保当前顶点是未访问节点中 dist 最小的
        for (int v = 1; v <= n; ++v) {
            if (!visited.count(v) && dist[v] < dist[u]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int Nv, Ne;
    cin >> Nv >> Ne;

    vector<vector<Edge>> adj(Nv + 1);

    for (int i = 0; i < Ne; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int K;
    cin >> K;

    while (K--) {
        vector<int> sequence(Nv);
        for (int i = 0; i < Nv; ++i) {
            cin >> sequence[i];
        }

        int source = sequence[0];  // 取序列首个顶点作为源点
        vector<int> dist;
        dijkstra(source, Nv, adj, dist);

        cout << (is_valid_dijkstra_sequence(sequence, dist) ? "Yes" : "No")
             << endl;
    }

    return 0;
}
