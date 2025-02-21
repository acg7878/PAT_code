#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
std::vector<std::vector<std::pair<int, int>>> graph;
int N, M, K, Ds;
const int INF = std::numeric_limits<int>::max();

std::vector<int> dijkstra(int start) {
    std::vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    //距离值为first，根据距离值进行自动排序
    pq.push({0, start});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

bool isServiceable(int gasStationIndex) {
    auto dist = dijkstra(gasStationIndex);
    for (int i = 1; i <= N; ++i) { //遍历1- N，因为为房子，不要直接int d: dist
        if (dist[i] == INF || dist[i] > Ds) {
            return false;
        }
    }
    return true;
}

void calculateDistances(int gasStationIndex, double& minDist, double& avgDist) {
    auto dist = dijkstra(gasStationIndex);
    minDist = INF;
    double sumDist = 0.0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] != INF) {
            minDist = std::min(minDist, static_cast<double>(dist[i]));
            sumDist += dist[i];
        }
    }
    avgDist = sumDist / N;
}

int main() {
    std::cin >> N >> M >> K >> Ds;
    int gas_start_index = N + 1;
    graph.resize(N + M + 1);
    while (K--) {
        std::string P1, P2;
        int p1, p2, dist;
        std::cin >> P1 >> P2 >> dist;
        isalpha(P1[0]) ? p1 = stoi(P1.substr(1)) + N : p1 = stoi(P1);
        isalpha(P2[0]) ? p2 = stoi(P2.substr(1)) + N : p2 = stoi(P2);
        graph[p1].push_back({p2, dist});
        graph[p2].push_back({p1, dist});
    }
    int bestGasStationIndex = -1;
    double bestMinDist = -1.0;
    double bestAvgDist = INF;
    for (int i = gas_start_index; i < gas_start_index + M; i++) {
        if (isServiceable(i)) {
            double minDist, avgDist;
            calculateDistances(i, minDist, avgDist);
            if (minDist > bestMinDist ||
                (minDist == bestMinDist && avgDist < bestAvgDist) ||
                (minDist == bestAvgDist && avgDist == bestAvgDist &&
                 i < bestGasStationIndex)) {
                bestMinDist = minDist;
                bestAvgDist = avgDist;
                bestGasStationIndex = i;
            }
        }
    }
    if (bestGasStationIndex == -1) {
        std::cout << "No Solution" << std::endl;
    } else {
        std::cout << "G" << bestGasStationIndex - N << std::endl;
        //printf("%.1f %.1f\n", bestMinDist, bestAvgDist);
        std::cout << std::fixed << std::setprecision(1) << bestMinDist << " "
                  << bestAvgDist << std::endl;
    }

    return 0;
}