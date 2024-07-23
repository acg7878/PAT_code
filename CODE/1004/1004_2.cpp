#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int N, M;
    cin >> N;
    if (N == 0)
        return 0;
    cin >> M;
    vector<vector<int>> tree(N+1);
    for (int i = 0; i < M; i++) {
        int ID, K;
        cin >> ID >> K;
        tree[ID].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> tree[ID][j];
        }
    }

    queue<int> pq;
    pq.push(1);
    vector<int> ans;
    while (!pq.empty()) {
        int size = pq.size();
        int leafs = 0;
        for (int i = 0; i < size; i++) {
            int node = pq.front();
            pq.pop();
            if (tree[node].empty())
                leafs++;
            else {
                for (int child : tree[node]) {
                    pq.push(child);
                }
            }
        }
        ans.push_back(leafs);
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i > 0)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
