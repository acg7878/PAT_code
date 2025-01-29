#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> a1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a1[i];
    }
    std::cin >> m;
    std::vector<int> a2(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> a2[i];
    }
    int cnt = 0;
    int target = (n + m + 1) / 2;
    int i = 0, j = 0;
    int ans;
    while (i < n && j < m) {
        if (a1[i] <= a2[j]) {
            ans = a1[i++];
        } else {
            ans = a2[j++];
        }
        if (++cnt == target) {
            break;
        }
    }
    if (i < n && cnt < target) {
        ans = a1[i + target - cnt - 1];
    } 
    else if (j < m && cnt < target) {
        ans = a2[j + target - cnt - 1];
    }
    std::cout << ans << std::endl;
    return 0;
}