#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
    std::vector<std::string> digits = {"zero", "one", "two",   "three", "four",
                                      "five", "six", "seven", "eight", "nine"};
    std::string num;
    std::cin >> num;
    int sum = 0;
    for(const char& digit : num) {
        sum += digit-'0';
    }
    if(sum==0){
        std::cout << digits[0] << std::endl;
        return 0;
    }
    std::vector<std::string> ans;
    while (sum>0) {
        std::string digit = digits[sum%10];
        ans.push_back(digit);
        sum/=10; 
    }
    std::reverse(ans.begin(), ans.end());
    for(size_t i=0;i<ans.size();i++){
        if(i>=1) std::cout << " ";
        std::cout << ans[i];
    }
    std::cout << std::endl;
}