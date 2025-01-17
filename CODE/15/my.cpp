#include <cctype>
#include <iostream>
#include <string>

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

std::string tenToRadixReverse(int num, int radix) {
    if (num == 0) return "0";
    std::string result;
    while (num > 0) {
        result += std::to_string(num % radix);
        num /= radix;
    }
    return result;
}

int radixToTen(const std::string& num, int radix) {
    int result = 0;
    for (char c : num) {
        result = result * radix + (c - '0');
    }
    return result;
}

int main() {
    int N, D;
    while (std::cin >> N && N >= 0) {
        std::cin >> D;
        if (!isPrime(N)) {
            std::cout << "No" << std::endl;
            continue;
        }
        std::string reversedRadix = tenToRadixReverse(N, D);
        int reversedNum = radixToTen(reversedRadix, D);
        if (isPrime(reversedNum)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}
