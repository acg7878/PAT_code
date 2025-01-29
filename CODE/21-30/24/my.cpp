#include <algorithm>
#include <iostream>
#include <string>
bool isPalindromic(const std::string& num) {
    std::string reversed_num = num;
    std::reverse(reversed_num.begin(), reversed_num.end());
    return num == reversed_num;
}

std::string add(const std::string num) {
    std::string origin_num = num;
    std::reverse(origin_num.begin(), origin_num.end());
    std::string result = "";
    int carry = 0;
    for (int i = num.size()-1; i >= 0; i--) {
        int digit1 = num[i] - '0';
        int digit2 = origin_num[i] - '0';
        int sum = digit1 + digit2 + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry > 0) {
        result += carry + '0';
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main(){
    std::string num;
    int k;
    std::cin >> num >> k;
    if (isPalindromic(num)) {
        std::cout << num << std::endl << 0 << std::endl;
        return 0;
    }
    for(int i=1;i<=k;i++){
        num = add(num);
        if(isPalindromic(num) || i==k){
            std::cout << num << std::endl << i << std::endl;
            return 0;
        }
    }
    return  0;
}