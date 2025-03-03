#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> nums(N);
    for(int i=0;i<N;i++){
        std::cin >> nums[i];
    }
    std::sort(nums.begin(),nums.end(),[](const std::string& a,const std::string& b){
        return a+b<b+a;
    });
    std::string result;
    for (const std::string& num : nums) {
        result += num;
    }
    size_t start = 0;
    while (result[start] == '0' && start < result.size()-1) start++; 
    result = result.substr(start);
    std::cout << result << std::endl;
}