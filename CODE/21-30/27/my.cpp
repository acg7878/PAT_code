#include <iostream>
#include <string>
#include <map>

std::string decimalTo13(int num) {
    if (num == 0) return "0";

    std::map<int, char> map = {{10, 'A'}, {11, 'B'}, {12, 'C'}};
    std::string result;

    while (num > 0) {
        int remainder = num % 13;
        if (remainder >= 10) {
            result = map[remainder] + result;
        } else {
            result = std::to_string(remainder) + result;
        }
        num /= 13;
    }

    return result;
}

int main() {
    int red, green, blue;
    std::cin >> red >> green >> blue;

    std::string red13 = decimalTo13(red);
    std::string green13 = decimalTo13(green);
    std::string blue13 = decimalTo13(blue);

    // 确保每个颜色值至少有两位
    if (red13.length() < 2) red13 = "0" + red13;
    if (green13.length() < 2) green13 = "0" + green13;
    if (blue13.length() < 2) blue13 = "0" + blue13;

    std::string result = red13 + green13 + blue13;

    std::cout << "#" << result << std::endl;

    return 0;
}