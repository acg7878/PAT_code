#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
int main(){
    int N,M,L;
    std::cin >> N >> M;
    std::unordered_map<int, int> colors; // 颜色，顺序
    for(int i=1;i<=M;i++) {
        int color;
        std::cin >> color;
        colors[color] = i;
    }
    std::cin >> L;
    std::vector<int> valid_color;
    for(int i=0;i<L;i++) {
        int color;
        std::cin >> color;
        if(colors.find(color)!=colors.end()){
            valid_color.push_back(colors[color]);
        }
    }
    int num = valid_color.size();
    int maxLength = 0;
    std::vector<int> dp(num,1);
    for(int i=0;i<num;i++){
        for(int j=0;j<i;j++){
            if(valid_color[i] >= valid_color[j]) {
                dp[i] = std::max(dp[i],dp[j]+1);
            }
        }
        maxLength = std::max(maxLength,dp[i]);
    }
    std::cout << maxLength << std::endl;
}