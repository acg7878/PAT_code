#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
struct Node {
    int address;
    int key;
    int next;
    Node(int x,int y,int z):address(x),key(y),next(z){};
};

void my_sort(std::vector<Node>& list) {
    for(int i = list.size()-1;i>=1;i--) {
        list[i].next = list[i-1].address;
    }
    std::reverse(list.begin(), list.end());
}

int main() {
    int head_address,N,K;
    std::cin >> head_address >> N >> K;
    std::unordered_map<int, Node> list;
    for(int i=0;i<N;i++) {
        int address,key,next;
        std::cin >> address >> key >> next;
        list[address] = Node{address,key,next};
    }
    int cur_address = head_address;
    int count = 0;
    std::vector<std::vector<Node>> order_list;
    int index = 0;
    while (list[cur_address].next != -1) {
        if(count!=K) {
            count++;
            order_list[index].push_back(list[cur_address]);
            cur_address = list[cur_address].next;
        } else {
            count=0;
            my_sort(order_list[index]);
            index++;
        }
    }
    for(int i=0;i<=order_list.size()-1;i++){
        if(i!=order_list.size()-1) {
            order_list[i].back().next = order_list[i+1].front().address;
        } else {
            order_list[i].back().next = -1;
        }
    }
}