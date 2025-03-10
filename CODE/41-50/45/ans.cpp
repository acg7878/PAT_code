#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n, m, l;
    std::cin >> n >> m;

    // 使用 unordered_map 存储颜色的偏好顺序
    std::unordered_map<int, int> preferenceOrder;
    for (int i = 1; i <= m; ++i) {
        int color;
        std::cin >> color;
        preferenceOrder[color] = i;
    }

    std::cin >> l;
    std::vector<int> validColors;
    for (int i = 0; i < l; ++i) {
        int color;
        std::cin >> color;
        // 如果该颜色在偏好列表中，将其偏好顺序添加到 validColors 向量中
        if (preferenceOrder.find(color) != preferenceOrder.end()) {
            validColors.push_back(preferenceOrder[color]);
        }
    }

    int num = validColors.size();
    std::vector<int> dp(num, 1);
    int maxLength = 0;

    // 动态规划求解最长不下降子序列
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < i; ++j) {
            if (validColors[i] >= validColors[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        maxLength = std::max(maxLength, dp[i]);
    }

    std::cout << maxLength << std::endl;
    return 0;
}