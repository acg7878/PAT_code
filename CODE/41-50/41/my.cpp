#include <algorithm>
#include <iostream>
#include <vector>
int main(){
    int N;
    std::cin >> N;
    std::vector<int> nums(N);
    int visited[10005];
    std::fill(visited,visited+10005,0);
    for(int i =0;i<N;i++){
        std::cin >> nums[i];
        visited[nums[i]]++;
    }
    for(int num : nums) {
        if(visited[num] == 1) {
            std::cout << num << std::endl;
            return 0;
        }
    }
    std::cout << "None" << std::endl;
}