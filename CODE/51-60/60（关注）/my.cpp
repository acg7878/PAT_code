#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

int getDigit(double num) {
    int count = 0;
    while (num > 1) {
        num /= 10;
        count++;
    }
    return count;
}

double saveN(double num, int n) {
    double factor = std::pow(10.0, n);
    return (double)((int)(num * factor)/factor);
}

std::string convert(double num, int target) {
    int digit_num = getDigit(num);
    num = num / std::pow(10, digit_num);
    num = saveN(num, target);
    std::ostringstream out;
    out << std::fixed << std::setprecision(target) << num;
    return out.str() + "*10^" + std::to_string(digit_num);
}

int main() {
    int n;
    double a, b;
    std::cin >> n >> a >> b;

    // 调用 convert 函数进行转换
    std::string result_a = convert(a, n);
    std::string result_b = convert(b, n);

    if (result_a == result_b) {
        std::cout << "YES" << " " << result_a;
    } else {
        std::cout << "NO" << " " << result_a << " " << result_b;
    }
    std::cout << std::endl;
    return 0;
}