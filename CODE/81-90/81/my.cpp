#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct number {
    long int numerator;
    long int denominator;
};

// 计算两个数的最大公约数（GCD），使用欧几里得算法
long int gcd(long int a, long int b) {
    while (b != 0) {
        long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 计算两个数的最小公倍数（LCM）
long int lcm(long int a, long int b) {
    return (a / gcd(a, b)) * b;
}

// 化简分数
void simplify(number& num) {
    if (num.numerator == 0) {
        num.numerator = 0;
        num.denominator = 1;
        return;
    }
    long int divisor = gcd(num.numerator, num.denominator);
    num.numerator /= divisor;
    num.denominator /= divisor;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<number> numbers(N);

    // 读取输入的分数
    for (int i = 0; i < N; i++) {
        std::string num;
        char temp;
        std::cin >> num;
        std::stringstream ss(num);
        ss >> numbers[i].numerator >> temp >> numbers[i].denominator;
    }
    long int commonDenominator = numbers[0].denominator;
    for (int i = 1; i < N; i++) {
        commonDenominator = lcm(commonDenominator, numbers[i].denominator);
    }
    number sum = {0, commonDenominator};
    for (int i = 0; i < N; i++) {
        long int factor = commonDenominator / numbers[i].denominator;
        sum.numerator += numbers[i].numerator * factor;
    }
    simplify(sum);

    if (sum.numerator < sum.denominator) {
        if (sum.numerator == 0)
            std::cout << "0" << std::endl;
        else
            std::cout << sum.numerator << "/" << sum.denominator << std::endl;
    } else {
        long int integer = sum.numerator / sum.denominator;
        sum.numerator -= (integer * sum.denominator);
        simplify(sum);
        std::cout << integer;
        if (sum.numerator!=0) {
            std::cout << " " << sum.numerator << "/" << sum.denominator
                  << std::endl;
        }else std::cout << std::endl;
    }
    return 0;
}