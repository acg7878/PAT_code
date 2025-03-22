#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        std::cin >> coins[i];
    }
    std::sort(coins.begin(),coins.end());
    int left = 0, right = N - 1;
    while (left < right) {
        int sum = coins[left] + coins[right];
        if (sum == M) {
            std::cout << coins[left] << " " << coins[right] << std::endl;
            return 0;
        } else if (sum > M)
            right--;    
        else
            left++;
    }
    std::cout << "No Solution" << std::endl;
}