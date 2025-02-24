#include <iostream>
#include <string>
#include <cmath>  // for std::abs

int main() {
    std::string input;
    std::cin >> input;

    // 找到 'E' 的位置
    std::size_t ePos = input.find('E');
    // 底数部分（去掉符号位和 'E'）
    // [1, ePos) 表示除符号和 'E' 以外的所有字符
    std::string base = input.substr(1, ePos - 1);

    // 指数部分转换为整数
    int exponent = std::stoi(input.substr(ePos + 1));

    // 处理符号
    if (input[0] == '-') {
        std::cout << '-';
    }

    // 若指数为负数
    if (exponent < 0) {
        std::cout << "0.";
        // 需要补 abs(exponent) - 1 个 '0'
        for (int i = 0; i < std::abs(exponent) - 1; ++i) {
            std::cout << '0';
        }
        // 将 base 中的数字（除去小数点）依次输出
        for (char c : base) {
            if (c != '.') {
                std::cout << c;
            }
        }
    }
    // 若指数 >= 0
    else {
        // 首先输出 base[0] (假设底数至少有一个有效数字)
        std::cout << base[0];

        // 准备从 base[2] 开始输出，这里 base[1] 应该是小数点
        // moveCount 表示已经向右移动的小数位数
        int moveCount = 0;
        std::size_t i = 2;            // 从 base[2] 开始
        std::size_t len = base.size();

        // 把小数部分尽量“平移” exponent 位
        while (i < len && moveCount < exponent) {
            std::cout << base[i];
            ++i;
            ++moveCount;
        }

        // 如果 base 已经输出完，但 exponent 还没用完，需要补 0
        if (i == len && moveCount < exponent) {
            for (int k = 0; k < exponent - moveCount; ++k) {
                std::cout << '0';
            }
        }
        // 如果 base 还没输出完，说明需要输出小数点和剩余的数字
        else if (i < len) {
            std::cout << '.';
            // 输出剩余字符
            for (; i < len; ++i) {
                std::cout << base[i];
            }
        }
    }

    std::cout << std::endl;
    return 0;
}
