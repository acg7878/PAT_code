#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> result, temp, coins;
int n, m;
bool found = false;

void dfs(int index, int sum) {
    if (sum == m) {
        result = temp;
        found = true;
        return;
    }
    if (sum > m || index >= n)
        return;

    for (int i = index; i < n; i++) {
        if (i > index && coins[i] == coins[i - 1])
            continue;
        temp.push_back(coins[i]);
        dfs(i + 1, sum + coins[i]);
        temp.pop_back();
        if (found)
            return;
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> coins[i];
    }
    std::sort(coins.begin(), coins.end());
    dfs(0, 0);
    if (found) {
        for (int i = 0; i < result.size(); i++) {
            if (i > 0)
                std::cout << " ";
            std::cout << result[i];
        }
        std::cout << std::endl;
    } else {
        std::cout << "No Solution" << std::endl;
    }

    return 0;
}