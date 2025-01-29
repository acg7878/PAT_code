#include <iostream>
#include <string>
#include <vector>

// 进制转换函数
std::string convert(std::string num, long long base) {
    if (num == "0") {
        return "0";
    }
    std::string result = "";
    long long number = std::stoll(num); // 转换为长整型
    std::vector<int> digits; // 存储每一位的结果

    // 进制转换
    while (number > 0) {
        long long remainder = number % base;
        digits.push_back(remainder); // 存入当前余数
        number /= base;
    }

    // 反转结果以获取正确顺序
    for (int i = digits.size() - 1; i >= 0; --i) {
        result += std::to_string(digits[i]);
    }
    return result;
}

// 判断是否是回文数
bool isPalindromic(const std::string& num) {
    int size = num.size();
    for (int i = 0; i < size / 2; i++) {
        if (num[i] != num[size - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string num;
    long long base;
    std::cin >> num >> base;

    // 转换数字为指定进制
    std::string ans = convert(num, base);

    // 判断是否是回文数
    std::cout << (isPalindromic(ans) ? "Yes" : "No") << std::endl;

    // 输出转换后的进制表示
    for (size_t i = 0; i < ans.size(); i++) {
        std::cout << ans[i];
        if (i < ans.size() - 1) {
            std::cout << " ";
        }
    }
    //std::cout << std::endl;

    return 0;
}
