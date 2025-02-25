#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
struct Node {
    int address;
    int key;
    int next;
    Node(): address(0),key(0),next(0){};
    Node(int x, int y, int z) : address(x), key(y), next(z) {}
};

void my_sort(std::vector<Node>& list) {
    for (int i = list.size() - 1; i >= 1; i--) {
        list[i].next = list[i - 1].address;
    }
    std::reverse(list.begin(), list.end());
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
    int count = 0;
    std::vector<std::vector<Node>> order_list(1); // 初始化一个子向量
    while (cur_address != -1) {
        if (count != K) {
            count++;
            order_list.back().push_back(list[cur_address]);
            cur_address = list[cur_address].next;
        } else {
            count = 0;
            my_sort(order_list.back());
            order_list.push_back(std::vector<Node>()); // 添加新的子向量
        }
    }

    for (int i = 0; i < order_list.size(); i++) {
        for (int j = 0; j < order_list[i].size(); j++) {
            if (j != order_list[i].size() - 1) {
                std::cout << std::setw(5) << std::setfill('0') << order_list[i][j].address << " "
                          << order_list[i][j].key << " "
                          << std::setw(5) << std::setfill('0') << order_list[i][j].next << std::endl;
            } else if (i != order_list.size() - 1) {
                std::cout << std::setw(5) << std::setfill('0') << order_list[i][j].address << " "
                          << order_list[i][j].key << " "
                          << std::setw(5) << std::setfill('0') << order_list[i + 1][0].address << std::endl;
            } else {
                std::cout << std::setw(5) << std::setfill('0') << order_list[i][j].address << " "
                          << order_list[i][j].key << " -1" << std::endl;
            }
        }
    }

    return 0;
}