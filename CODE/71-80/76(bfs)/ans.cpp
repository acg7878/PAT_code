#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct Node {
    int id, layer;
};

vector<vector<int>> adjList;

int bfs(const Node& startNode, int maxLayer) {
    unordered_set<int> visited;
    queue<Node> q;
    q.push(startNode);
    visited.insert(startNode.id);

    int cnt = 0;
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.layer >= maxLayer) {
            continue;
        }

        for (int nextId : adjList[curr.id]) {
            if (visited.find(nextId) == visited.end()) {
                visited.insert(nextId);
                q.push({nextId, curr.layer + 1});
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false); // 关闭C++与stdio的同步，提高I/O效率
    cin.tie(nullptr); // 解除cin与cout的绑定

    int n, l, m, k;
    cin >> n >> l;
    adjList.resize(n + 1);

    // 构建邻接表
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        while (m--) {
            int temp;
            cin >> temp;
            adjList[temp].push_back(i);
        }
    }

    // 处理查询
    cin >> k;
    while (k--) {
        int tid;
        cin >> tid;
        Node tnode = {tid, 0};
        cout << bfs(tnode, l) << '\n';
    }

    return 0;
}
