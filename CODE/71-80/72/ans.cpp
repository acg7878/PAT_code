#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

int N, M, K, Ds;
vector<vector<pair<int, int>>> graph;  // 邻接表存储图，每个元素是{节点, 距离}

// Dijkstra算法求单源最短路径
vector<int> dijkstra(int start) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int d = pq.top().first;   //距离
        int u = pq.top().second;  //节点index
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first; // index
            int w = edge.second;// 距离
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// 检查加油站是否满足所有房屋都在服务范围内
bool isServiceable(int gasStationIndex) {
    auto dist = dijkstra(gasStationIndex);
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == INF || dist[i] > Ds) {
            return false;
        }
    }
    return true;
}

// 计算加油站到所有房屋的最小距离和平均距离
void calculateDistances(int gasStationIndex, double& minDist, double& avgDist) {
    auto dist = dijkstra(gasStationIndex);
    minDist = INF;
    double sumDist = 0.0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i]!= INF) {
            minDist = min(minDist, static_cast<double>(dist[i]));
            sumDist += dist[i];
        }
    }
    avgDist = sumDist / N;
}

int main() {
    cin >> N >> M >> K >> Ds;
    int gas_start_index = N + 1;
    graph.resize(N + M + 1);
    while (K--) {
        string P1, P2;
        int p1, p2, dist;
        cin >> P1 >> P2 >> dist;
        isalpha(P1[0])? p1 = stoi(P1.substr(1)) + N : p1 = stoi(P1);
        isalpha(P2[0])? p2 = stoi(P2.substr(1)) + N : p2 = stoi(P2);
        graph[p1].push_back({p2, dist});
        graph[p2].push_back({p1, dist});
    }

    int bestGasStationIndex = -1;
    double bestMinDist = -1.0;
    double bestAvgDist = INF;
    for (int i = gas_start_index; i <= gas_start_index + M - 1; ++i) {
        if (isServiceable(i)) {
            double minDist, avgDist;
            calculateDistances(i, minDist, avgDist);
            if (minDist > bestMinDist || (minDist == bestMinDist && avgDist < bestAvgDist) ||
                (minDist == bestMinDist && avgDist == bestAvgDist && i < bestGasStationIndex)) {
                bestGasStationIndex = i;
                bestMinDist = minDist;
                bestAvgDist = avgDist;
            }
        }
    }

    if (bestGasStationIndex == -1) {
        cout << "No Solution" << endl;
    } else {
        cout << "G" << bestGasStationIndex - N << endl;
        printf("%.1f %.1f\n", bestMinDist, bestAvgDist);
    }

    return 0;
}