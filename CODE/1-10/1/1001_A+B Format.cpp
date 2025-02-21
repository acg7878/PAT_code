#include <iostream>
#include <string>

// 将数字格式化为带有千位分隔符的字符串
std::string formatNumber(long long number) {
    std::string numStr = std::to_string(number);
    int insertPosition = numStr.length() - 3;
    while (insertPosition > 0 && (numStr[0] != '-' || insertPosition > 1)) {
        numStr.insert(insertPosition, ",");
        insertPosition -= 3;
    }
    return numStr;
}

int main() {
    long long a, b;
    std::cin >> a >> b; // 读取输入的两个整数
    long long sum = a + b; // 计算它们的和
    std::cout << formatNumber(sum) << std::endl; // 输出格式化后的结果
    return 0;
}
