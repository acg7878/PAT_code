#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>


const int inf = INT_MAX;
int cmax, n, sp, m;
std::vector<int> weight(510);
std::vector<std::vector<int>> e(510, std::vector<int>(510, inf));
std::vector<int> dis(510, inf);
std::vector<bool> visited(510, false);
std::vector<std::vector<int>> pre(510);
std::vector<int> path, tempPath;
int minNeed = inf, minBack = inf;

void dijkstra() {
  dis[0] = 0;
  for (int i = 0; i <= n; i++) {
    int u = -1, minn = inf;
    for (int j = 0; j <= n; j++) {
      if (!visited[j] && dis[j] < minn) {
        u = j;
        minn = dis[j];
      }
    }
    if (u == -1)
      break;
    visited[u] = true;
    for (int v = 0; v <= n; v++) {
      if (!visited[v] && e[u][v] != inf) {
        if (dis[v] > dis[u] + e[u][v]) {
          dis[v] = dis[u] + e[u][v];
          pre[v].clear();
          pre[v].push_back(u);
        } else if (dis[v] == dis[u] + e[u][v]) {
          pre[v].push_back(u);
        }
      }
    }
  }
}

void dfs(int v) {
  if (v == 0) {
    tempPath.push_back(v);
    int need = 0, back = 0;
    for (int i = tempPath.size() - 1; i >= 0; i--) {
      int id = tempPath[i];
      if (weight[id] > 0) {
        back += weight[id];
      } else {
        if (back > (0 - weight[id])) {
          back += weight[id];
        } else {
          need += (0 - weight[id]) - back;
          back = 0;
        }
      }
    }
    if (need < minNeed) {
      minNeed = need;
      minBack = back;
      path = tempPath;
    } else if (need == minNeed && back < minBack) {
      minBack = back;
      path = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  tempPath.push_back(v);
  for (size_t i = 0; i < pre[v].size(); i++) {
    dfs(pre[v][i]);
  }
  tempPath.pop_back();
}

int main() {
  std::fill(e.begin(), e.end(), std::vector<int>(510, inf));
  std::fill(dis.begin(), dis.end(), inf);
  std::cin >> cmax >> n >> sp >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> weight[i];
    weight[i] = weight[i] - cmax / 2;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    std::cin >> e[a][b];
    e[b][a] = e[a][b];
  }
  dijkstra();
  dfs(sp);
  printf("%d 0", minNeed);
  for (int i = path.size() - 2; i >= 0; i--)
    printf("->%d", path[i]);
  printf(" %d\n", minBack);
  return 0;
}