#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<int, std::string> units = {
    {2, "Shi"},     {3, "Bai"},     {4, "Qian"},     {5, "Wan"},
    {6, "Shi"}, {7, "Bai"}, {8, "Qian"}, {9, "Yi"},
    {10, "Shi"}, {11, "Bai"}, {12, "Qian"}};
std::unordered_map<char, std::string> numberToStr = {
    {'0', "ling"}, {'1', "yi"},  {'2', "er"}, {'3', "san"}, {'4', "si"},
    {'5', "wu"},   {'6', "liu"}, {'7', "qi"}, {'8', "ba"},  {'9', "jiu"}};

int main() {
    std::string number;
    std::cin >> number;
    std::vector<std::string> result;

    // 处理负数
    if (number[0] == '-') {
        result.push_back("Fu");
        number = number.substr(1);
    } 
    // 处理输入为 0 的情况
    else if (number == "0") {
        std::cout << "ling" << std::endl;
        return 0;
    }

    bool hasZero = false;
    for (size_t i = 0; i < number.size(); i++) {
        if (number[i] == '0') {
            hasZero = true;
            // 处理连续零跨越 4 位的情况，例如万、亿
            if ((number.size() - i) % 4 == 1 && (number.size() - i) > 1) {
                if (result.empty() || result.back() != units[number.size() - i]) {
                    result.push_back(units[number.size() - i]);
                }
            }
        } else {
            if (hasZero) {
                result.push_back("ling");
                hasZero = false;
            }
            result.push_back(numberToStr[number[i]]);
            if (i != number.size() - 1) {
                result.push_back(units[number.size() - i]);
            }
        }
    }

    // 去除多余的 ling
    for (size_t i = result.size() - 1; i > 0; i--) {
        if (result[i] == "ling") {
            result.pop_back();
        } else {
            break;
        }
    }

    // 输出结果
    for (size_t i = 0; i < result.size(); i++) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}