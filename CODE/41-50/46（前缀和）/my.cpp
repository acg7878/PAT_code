#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
int main(){
    int n;
    std::cin >> n;
    std::vector<int> exits(n+1);
    std::vector<int> prefix_sum(n+1,0);
    for(int i=1;i<=n;i++){
        std::cin >> exits[i];
        prefix_sum[i]  = prefix_sum[i-1] + exits[i];
    }
    int m;
    int total_sum = prefix_sum[n];
    std::cin >> m;
    while (m--) {
        int u1,u2;
        std::cin >> u1 >> u2;
        if(u1 > u2) std::swap(u1,u2);
        int dist1 = prefix_sum[u2-1] - prefix_sum[u1-1];
        int dist2 = total_sum - dist1;
        std::cout << std::min(dist1,dist2) << std::endl;
    }

}