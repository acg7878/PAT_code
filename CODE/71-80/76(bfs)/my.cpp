#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

int bfs(const std::vector<std::vector<int>>& social_network, int start_id, int L) {
    std::queue<std::pair<int, int>> q; // 队列存储节点和当前层级
    std::unordered_set<int> visited; // 记录访问过的节点
    q.push({start_id, 0});
    visited.insert(start_id);
    int forward_count = 0;

    while (!q.empty()) {
        auto [current_id, level] = q.front();
        q.pop();

        if (level >= L) continue; // 超过层级限制，停止扩展

        for (int neighbor : social_network[current_id]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, level + 1});
                forward_count++;
            }
        }
    }

    return forward_count;
}

int main() {
    int N, L;
    std::cin >> N >> L;
    std::vector<std::vector<int>> social_network(N + 1); // 使用 N + 1 以便从 1 开始索引
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