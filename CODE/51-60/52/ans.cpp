#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {
    int address;  // 地址
    int key;      // 键值
    int next;     // 下一节点的地址
};

int main() {
    int N, head_address;
    cin >> N >> head_address;  // 读取节点数和头节点地址

    unordered_map<int, Node> node_map;  // 存储节点
    for (int i = 0; i < N; ++i) {
        int address, key, next;
        cin >> address >> key >> next;
        node_map[address] = {address, key, next};  // 存储节点
    }

    // 处理链表：只存储从 head_address 能够访问到的节点
    vector<Node> linked_list;
    int current_address = head_address;
    while (current_address != -1 && node_map.find(current_address) != node_map.end()) {
        linked_list.push_back(node_map[current_address]);
        current_address = node_map[current_address].next;  // 跳到下一个节点
    }

    // 排除无效链表的情况
    if (linked_list.empty()) {
        cout << "0 -1" << endl;
        return 0;
    }

    // 按照 key 升序排序
    sort(linked_list.begin(), linked_list.end(), [](const Node& a, const Node& b) {
        return a.key < b.key;
    });

    // 更新 Next 地址
    for (size_t i = 0; i < linked_list.size() - 1; ++i) {
        linked_list[i].next = linked_list[i + 1].address;
    }
    linked_list.back().next = -1;  // 最后一个节点的 Next 设置为 -1

    // 输出排序后链表的信息
    printf("%zu %05d\n", linked_list.size(), linked_list[0].address);
    for (const auto& node : linked_list) {
        if (node.next == -1) {
            printf("%05d %d -1\n", node.address, node.key);
        } else {
            printf("%05d %d %05d\n", node.address, node.key, node.next);
        }
    }

    return 0;
}
