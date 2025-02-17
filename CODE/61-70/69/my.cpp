#include <algorithm>
#include <iostream>
#include <string>

std::string kaprekarCalculation(const std::string& input) {
    std::string num = input;
    std::string reverse_num = num;
    std::reverse(reverse_num.begin(), reverse_num.end());
    std::sort(num.begin(), num.end(), std::greater<>());
    std::sort(reverse_num.begin(), reverse_num.end());
    int new_num = std::stoi(num) - std::stoi(reverse_num);
    std::string result = std::to_string(new_num);
    while (result.size() < 4) {
        result = '0' + result;
    }
    std::cout << num << " - " << reverse_num << " = " << result << std::endl;
    return result;
}

int main() {
    std::string origin_num;
    std::cin >> origin_num;
    while (origin_num.size() < 4) {
        origin_num = '0' + origin_num;
    }
    bool state = true;
    for (int i = 1; i < 4; i++) {
        if (origin_num[i] != origin_num[i - 1]) {
            state = false;
        }
    }
    if (state) {
        std::cout << origin_num << " - " << origin_num << " = 0000\n";
        return 0;
    }
    if (origin_num == "6174") {
        kaprekarCalculation(origin_num);
    } else {
        while (origin_num != "6174") {
            origin_num = kaprekarCalculation(origin_num);
        }
    }
    return 0;
}