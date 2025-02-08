#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
struct Node {
    int addr;
    int key;
    int next;
};
bool cmp(Node& a, Node& b) {
    return a.key < b.key;
}
int main() {
    int n, head_addr;
    std::cin >> n >> head_addr;
    std::unordered_map<int, Node> list;
    for (int i = 0; i < n; i++) {
        int addr, key, next;
        std::cin >> addr >> key >> next;
        list[addr] = {addr, key, next};
    }
    std::vector<Node> sorted_list;
    int cur_addr = head_addr;
    while (cur_addr != -1 && (list.find(cur_addr) != list.end())) {
        sorted_list.push_back(list[cur_addr]);
        cur_addr = list[cur_addr].next;
    }
    if (sorted_list.empty()) {
        std::cout << "0 -1" << std::endl;
        return 0;
    }
    std::sort(sorted_list.begin(), sorted_list.end(), cmp);
    for (size_t i = 0; i < sorted_list.size() - 1; i++) {
        sorted_list[i].next = sorted_list[i + 1].addr;
    }
    sorted_list.back().next = -1;
    std::cout << sorted_list.size() << " " << std::setw(5) << std::setfill('0')
              << sorted_list[0].addr << std::endl;
    for (auto& node : sorted_list) {
        std::cout << std::setw(5) << std::setfill('0') << node.addr << " "
                  << node.key << " ";
        if (node.next != -1)
            std::cout << std::setw(5) << std::setfill('0') << node.next << std::endl;
        else
            std::cout << -1 << std::endl;
    }
}