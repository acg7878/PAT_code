#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> cost;
std::vector<bool> visited;
std::vector<int> dist;
std::vector<int> total_cost;
std::vector<int> prev;

void dijkstra(int start,int n){
    dist.assign(n,INT_MAX);
    total_cost.assign(n,INT_MAX);
    prev.assign(n,-1);
    visited.assign(n,false);

    dist[start] = 0;
    total_cost[start] = 0;

    using Node = std::pair<int, int>;
    std::priority_queue<Node,std::vector<Node>,std::greater<Node>> pq;
    pq.push({0,start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])continue;
        visited[u] = true;

        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v] != INT_MAX){
                int newDist = dist[u] + graph[u][v];
                int newCost = total_cost[u] + cost[u][v];

                if(newDist < dist[v] || (newDist == dist[v] && newCost < total_cost[v])){
                    dist[v] = newDist;
                    total_cost[v] = newCost;
                    prev[v] = u;
                    pq.push({dist[v],v});
                }
            }
        }
    }
}


std::vector<int> getPath(int dest) {
    std::vector<int> path;
    for(int v=dest;v!=-1;v=prev[v]){
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    int N, M, S, D;
    std::cin >> N >> M >> S >> D;
    graph.resize(N,std::vector<int>(N,INT_MAX));
    cost.resize(N,std::vector<int>(N,INT_MAX));
    for (int i = 0; i < M; ++i) {
        int city1, city2, dist, cst;
        std::cin >> city1 >> city2 >> dist >> cst;
        graph[city1][city2] = dist;
        graph[city2][city1] = dist;
        cost[city1][city2] = cst;
        cost[city2][city1] = cst;
    }
    dijkstra(S, N);
    std::vector<int> path = getPath(D);
    for (int node : path) {
        std::cout << node << " ";
    }
    std::cout << dist[D] << " " << total_cost[D] << "\n";

}