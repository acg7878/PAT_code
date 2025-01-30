#include <iostream>
#include <stack>
#include <string>
#include <vector>

const int maxn = 100010;

class BIT {
public:
    std::vector<int> tree;
    int size;

    BIT(int n) : size(n) {
        tree.resize(n + 1, 0);  // 调整大小为 n + 1
    }

    int lowbit(int i) {
        return i & (-i);
    }

    void update(int index, int val) {
        for (int i = index; i <= size; i += lowbit(i)) {
            tree[i] += val;
        }
    }

    int query(int index) {
        int sum = 0;
        for (int i = index; i >= 1; i -= lowbit(i)) {
            sum += tree[i];
        }
        return sum;
    }
};

int peekMedian(BIT& Bit, int stackSize) {
    int left = 1, right = Bit.size;
    int k = (stackSize + 1) / 2;  // 基于栈的大小计算 k
    while (left < right) {
        int mid = (left + right) / 2;
        if (Bit.query(mid) >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    BIT Bit(maxn);
    std::stack<int> stk;
    int n;
    std::cin >> n;  // 初始化 n
    while (n--) {
        std::string command;
        std::cin >> command;
        if (command == "Push") {
            int key;
            std::cin >> key;
            stk.push(key);
            Bit.update(key, 1);
        } else if (command == "Pop") {
            if (!stk.empty()) {
                Bit.update(stk.top(), -1);
                std::cout << stk.top() << std::endl;
                stk.pop();
            } else {
                std::cout << "Invalid\n";
            }
        } else {
            if (!stk.empty()) {
                std::cout << peekMedian(Bit, stk.size()) << std::endl;  // 传递栈的大小
            } else {
                std::cout << "Invalid\n";
            }
        }
    }
    return 0;
}