#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

// 定义节点结构体
struct Node {
    int address;
    int key;
    int next;
    Node() : address(0), key(0), next(0) {}
    Node(int x, int y, int z) : address(x), key(y), next(z) {}
};

// 反转一组节点
void reverseGroup(std::vector<Node>& group) {
    for (int i = group.size() - 1; i >= 1; i--) {
        group[i].next = group[i - 1].address;
    }
    std::reverse(group.begin(), group.end());
}

// 优化后的打印函数
void printList(const std::vector<std::vector<Node>>& order_list) {
    std::vector<Node> flatList;
    // 将所有分组的节点合并到一个向量中
    for (const auto& group : order_list) {
        flatList.insert(flatList.end(), group.begin(), group.end());
    }
    // 遍历合并后的向量进行打印
    for (size_t i = 0; i < flatList.size(); ++i) {
        std::cout << std::setw(5) << std::setfill('0') << flatList[i].address
                  << " " << flatList[i].key << " ";
        if (i < flatList.size() - 1) {
            std::cout << std::setw(5) << std::setfill('0')
                      << flatList[i + 1].address;
        } else {
            std::cout << "-1";
        }
        std::cout << std::endl;
    }
}

int main() {
    int head_address, N, K;
    std::cin >> head_address >> N >> K;
    std::unordered_map<int, Node> list;
    for (int i = 0; i < N; i++) {
        int address, key, next;
        std::cin >> address >> key >> next;
        list[address] = Node{address, key, next};
    }

    int cur_address = head_address;
    std::vector<std::vector<Node>> order_list;
    std::vector<Node> current_group;

    while (cur_address != -1) {
        current_group.push_back(list[cur_address]);
        cur_address = list[cur_address].next;
        if (current_group.size() == K) {
            reverseGroup(current_group);
            order_list.push_back(current_group);
            current_group.clear();
        }
    }

    // 处理最后一组不足 K 个节点的情况
    if (!current_group.empty()) {
        for (int i = 0; i < current_group.size() - 1; i++) {
            current_group[i].next = current_group[i + 1].address;
        }
        order_list.push_back(current_group);
    }

    printList(order_list);

    return 0;
}