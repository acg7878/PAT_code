#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to convert a number to a given base
vector<int> convertToBase(int number, int base) {
    vector<int> result;
    while (number > 0) {
        result.push_back(number % base);
        number /= base;
    }
    reverse(result.begin(), result.end()); // Reverse to get the correct order
    return result;
}

// Function to check if a number is palindromic in a given base
bool isPalindrome(const vector<int>& digits) {
    int left = 0, right = digits.size() - 1;
    while (left < right) {
        if (digits[left] != digits[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int N, b;
    cin >> N >> b;

    vector<int> convertedNumber = convertToBase(N, b);
    bool palindrome = isPalindrome(convertedNumber);

    cout << (palindrome ? "Yes" : "No") << endl;

    for (size_t i = 0; i < convertedNumber.size(); i++) {
        if (i > 0) cout << " ";
        cout << convertedNumber[i];
    }
    cout << endl;

    return 0;
}
