#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    if (N == 0) return 0;
    cin >> M;

    vector<vector<int>> tree(N + 1);
    for (int i = 0; i < M; ++i) {
        int ID, K;
        cin >> ID >> K;
        tree[ID].resize(K);
        for (int j = 0; j < K; ++j) {
            cin >> tree[ID][j];
        }
    }

    queue<int> q;
    q.push(1); // 根节点ID为1
    vector<int> leafCount;
    while (!q.empty()) {
        int size = q.size();
        int leafs = 0;
        for (int i = 0; i < size; ++i) {
            int node = q.front();
            q.pop();
            if (tree[node].empty()) {
                ++leafs;
            } else {
                for (int child : tree[node]) {
                    q.push(child);
                }
            }
        }
        leafCount.push_back(leafs);
    }

    for (int i = 0; i < leafCount.size(); ++i) {
        if (i > 0) cout << " ";
        cout << leafCount[i];
    }
    cout << endl;

    return 0;
}
