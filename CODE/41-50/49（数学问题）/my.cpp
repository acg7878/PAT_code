#include <iostream>
int main() {
    int N;
    std::cin >> N;
    int digit = 1;
    int totalDigit = 0;
    int leftDigit, rightDigit, curDigit;
    while (N / digit) {
        leftDigit = N / (digit * 10);
        curDigit = (N / digit) % 10;
        rightDigit = N % digit;

        if (curDigit == 0) {
            totalDigit += leftDigit * digit;
        } else if (curDigit == 1) {
            totalDigit += leftDigit * digit + rightDigit + 1;
        } else {
            totalDigit += (leftDigit + 1) * digit;
        }
        digit *= 10;
    }
    std::cout << totalDigit << std::endl;
}