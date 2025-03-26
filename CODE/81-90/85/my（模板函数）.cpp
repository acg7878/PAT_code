#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    int n, p;
    std::cin >> n >> p;
    std::vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());
    int result = 1;
    for (int i = 0; i < n; i++) {
        result = std::max(
            (int)(std::upper_bound(vec.begin(), vec.end(), vec[i] * p) -
                  (vec.begin() + i)),
            result);
    }
    std::cout << result << std::endl;
}