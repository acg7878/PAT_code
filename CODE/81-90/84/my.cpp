#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string ori_str;
    std::getline(std::cin, ori_str);
    std::transform(ori_str.begin(), ori_str.end(), ori_str.begin(), [](char c) { return std::toupper(c); });

    std::string out_str;
    std::getline(std::cin, out_str);
    std::transform(out_str.begin(), out_str.end(), out_str.begin(), [](char c) { return std::toupper(c); });

    std::unordered_set<char> outputKeys;

    for (char c : ori_str) {
        if (out_str.find(c) == std::string::npos && outputKeys.find(c) == outputKeys.end()) {
            std::cout << c;
            outputKeys.insert(c);
        }
    }
    std::cout << std::endl;

    return 0;
}