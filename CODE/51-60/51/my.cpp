#include <iostream>
#include <stack>
#include <vector>
int main() {
    int m, n, k;
    std::cin >> m >> n >> k;
    while (k--) {
        std::vector<int> vec(n + 1);
        std::stack<int> stk;
        for (int i = 1; i <= n; i++) {
            std::cin >> vec[i];
        }
        int cur = 1;
        for (int j = 1; j <= n; j++) {
            stk.push(j);
            if (stk.size() > m)
                break;
            while (!stk.empty() && stk.top() == vec[cur]) {
                stk.pop();
                cur++;
            }
        }
        if (cur == n + 1)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}