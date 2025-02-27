#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

int bfs(const std::vector<std::vector<int>>& social_network, int start_id,
        int L) {
    std::queue<std::pair<int, int>> q;
    std::unordered_set<int> visited;
    q.push({start_id, 0});
    visited.insert(start_id);
    int cnt = 0;
    while (!q.empty()) {
        auto [cur_id, level] = q.front();
        q.pop();
        if(level >= L) continue;
        for (int next_id : social_network[cur_id]) {
            if (visited.find(next_id) == visited.end()) {
                q.push({next_id, level + 1});
                visited.insert(next_id);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int N, L;
    std::cin >> N >> L;
    std::vector<std::vector<int>> social_network(
        N + 1);  // 使用 N + 1 以便从 1 开始索引
    for (int i = 1; i <= N; i++) {
        int num;
        std::cin >> num;
        while (num--) {
            int temp;
            std::cin >> temp;
            social_network[temp].push_back(i);
        }
    }

    int query_num;
    std::cin >> query_num;
    while (query_num--) {
        int query_id;
        std::cin >> query_id;
        int result = bfs(social_network, query_id, L);
        std::cout << result << std::endl;
    }

    return 0;
}