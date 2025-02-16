#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> coins, result, temp;
int N, M;
bool found = false; // 标记是否找到解

void dfs(int index, int sum) {
    if (sum == M) {
        result = temp;
        found = true;
        return;
    }
    if (sum > M || index >= N) return;

    for (int i = index; i < N; i++) {
        if (i > index && coins[i] == coins[i - 1]) continue; // 去重优化
        temp.push_back(coins[i]);
        dfs(i + 1, sum + coins[i]);
        temp.pop_back();
        if (found) return; // 立即终止搜索
    }
}

int main() {
    cin >> N >> M;
    coins.resize(N);
    for (int i = 0; i < N; i++) cin >> coins[i];

    sort(coins.begin(), coins.end()); // 先排序，保证字典序最小

    dfs(0, 0);

    if (found) {
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    } else {
        cout << "No Solution" << endl;
    }

    return 0;
}
