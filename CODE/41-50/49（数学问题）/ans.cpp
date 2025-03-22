#include <iostream>
using namespace std;

int countOnes(int number) {
    int totalCount = 0;
    int digitPlace = 1;
    int leftPart, currentDigit, rightPart;

    while (number / digitPlace) {
        leftPart = number / (digitPlace * 10);
        currentDigit = (number / digitPlace) % 10;
        rightPart = number % digitPlace;

        if (currentDigit == 0) {
            totalCount += leftPart * digitPlace;
        } else if (currentDigit == 1) {
            totalCount += leftPart * digitPlace + rightPart + 1;
        } else {
            totalCount += (leftPart + 1) * digitPlace;
        }

        digitPlace *= 10;
    }

    return totalCount;
}

int main() {
    int inputNumber;
    cin >> inputNumber;
    int result = countOnes(inputNumber);
    cout << result << endl;

    return 0;
}
