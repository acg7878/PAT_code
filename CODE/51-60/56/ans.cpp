#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int weight, index, rank, index0;
};

bool cmp1(const Node& a, const Node& b) {
    return a.index0 < b.index0;
}

int main() {
    int n, g;
    cin >> n >> g;

    vector<int> v(n);
    vector<Node> w(n);

    // 读取输入
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
    }

    // 使用 queue 进行处理
    queue<Node> q;
    for (const auto& node : w) {
        q.push(node);
    }

    while (!q.empty()) {
        int size = q.size();
        if (size == 1) {
            Node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }

        int group = size / g;
        if (size % g != 0)
            group += 1;

        Node maxnode;
        int maxn = -1, cnt = 0;

        for (int i = 0; i < size; i++) {
            Node temp = q.front();
            q.pop();
            w[temp.index].rank = group + 1;
            cnt++;

            if (temp.weight > maxn) {
                maxn = temp.weight;
                maxnode = temp;
            }

            if (cnt == g || i == size - 1) {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    // 排序并输出结果
    sort(w.begin(), w.end(), cmp1);
    for (int i = 0; i < n; i++) {
        if (i != 0)
            cout << " ";
        cout << w[i].rank;
    }
    cout << endl;
    return 0;
}
