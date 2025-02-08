#include <iostream>
#include <map>
#include <vector>
struct Node {
    int index;
    int weight;
    bool isRoot = true;
};
int n, m, s;
std::vector<std::vector<int>> ans;
std::map<int, std::vector<Node>> trees;
std::vector<Node> nodes;
bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    size_t min_size = std::min(a.size(), b.size());
    for (size_t i = 0; i < min_size; ++i) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return a.size() > b.size();
}
void dfs(int root, std::vector<int> path, int total_weight) {
    path.push_back(nodes[root].weight);
    total_weight += nodes[root].weight;
    if (total_weight == s) {
        if (!trees[root].empty())
            return;
        ans.push_back(path);
        return;
    }
    if (total_weight > s) {
        return;
    }
    for (Node node : trees[root]) {
        dfs(node.index, path, total_weight);
    }
}
int main() {
    std::cin >> n >> m >> s;
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
        nodes[i].index = i;
        std::cin >> nodes[i].weight;
    }

    for (int i = 0; i < m; i++) {
        int index, k;
        std::cin >> index >> k;
        while (k--) {
            int child_index;
            std::cin >> child_index;
            nodes[child_index].isRoot = false;
            trees[index].push_back(nodes[child_index]);
        }
    }
    // find root
    for (Node& node : nodes) {
        if (node.isRoot) {
            std::vector<int> path;
            dfs(node.index, path, 0);
        }
    }
    std::sort(ans.begin(), ans.end(), compare);
    for (const auto& path : ans) {
        for (size_t i = 0; i < path.size(); i++) {
            if (i > 0)
                std::cout << " ";
            std::cout << path[i];
        }
        std::cout << std::endl;
    }
    return 0;
}