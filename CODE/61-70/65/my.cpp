#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

std::string add(const std::string& num1, const std::string& num2) {
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    std::string result;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += num1[i--] - '0';
        if (j >= 0)
            sum += num2[j--] - '0';
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string sub(const std::string& num1, const std::string& num2) {
    bool negative = false;
    std::string a = num1;
    std::string b = num2;
    if (a < b) {
        std::swap(a, b);
        negative = true;
    }
    int borrow = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    std::string result;
    while (i >= 0 || j >= 0) {
        int diff =
            (i >= 0 ? a[i--] - '0' : 0) - (j >= 0 ? b[j--] - '0' : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    if (negative) {
        result.insert(result.begin(), '-');
    }
    return result;
}

std::string sub_or_add(std::string a, std::string b) {
    bool is_a_negative = (a[0] == '-');
    bool is_b_negative = (b[0] == '-');
    if (is_a_negative)
        a = a.substr(1);
    if (is_b_negative)
        b = b.substr(1);

    std::string result;
    if (is_a_negative == is_b_negative) {
        result = add(a, b);
        if (is_a_negative)
            result = '-' + result;
    } else {
        if (is_a_negative) {
            result = sub(b, a);
        } else {
            result = sub(a, b);
        }
    }
    return result;
}

bool compare(const std::string& num1, const std::string& num2) {
    bool is_one_negative = (num1[0] == '-');
    bool is_two_negative = (num2[0] == '-');
    if (is_one_negative == is_two_negative) {
        if (num1.size() == num2.size()) {
            int i = 1;
            for (size_t i = 0; i < num1.size(); ++i) {
                if (num1[i] != num2[i]) {
                    return is_one_negative ? num1[i] < num2[i]
                                           : num1[i] > num2[i];
                }
            }
            // 根本没必要一位一位比较，因为当位数相同的时候可以直接使用比较符号“<或>”
            return false;
        } else {
            return is_one_negative ? num1.size() < num2.size()
                                   : num1.size() > num2.size();
        }
        return false;
    } else {
        return !is_one_negative;
    }
}

int main() {
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        std::string a, b, c;
        std::cin >> a >> b >> c;
        printf("Case #%d: ", i);
        if (compare(sub_or_add(a, b), c)) {
            std::cout << "true" << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }
    }
}