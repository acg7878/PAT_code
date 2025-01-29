#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node {
    char data;
    int next;
};

int main() {
    int addr1, addr2, n;
    cin >> addr1 >> addr2 >> n;
    
    unordered_map<int, Node> nodes; // 存储链表节点信息
    
    for (int i = 0; i < n; i++) {
        int address, next;
        char data;
        cin >> address >> data >> next;
        nodes[address] = {data, next};
    }
    
    // 记录第一个链表访问过的节点
    unordered_set<int> visited;
    while (addr1 != -1) {
        visited.insert(addr1);
        addr1 = nodes[addr1].next;
    }

    // 遍历第二个链表，找到公共后缀的起始位置
    while (addr2 != -1) {
        if (visited.count(addr2)) {
            printf("%05d\n", addr2);
            return 0;
        }
        addr2 = nodes[addr2].next;
    }

    cout << "-1\n";
    return 0;
}
