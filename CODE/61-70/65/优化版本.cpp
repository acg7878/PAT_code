#include <algorithm>
#include <iostream>
#include <string>

std::string add(const std::string& num1, const std::string& num2) {
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
    std::string result;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry + (i >= 0 ? num1[i--] - '0' : 0) + (j >= 0 ? num2[j--] - '0' : 0);
        result += (sum % 10 + '0');
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string sub(std::string a, std::string b) {
    if (a < b) {
        std::swap(a, b);
        std::string res = sub(a, b);
        return '-' + res;
    }

    int borrow = 0, i = a.size() - 1, j = b.size() - 1;
    std::string result;
    
    while (i >= 0 || j >= 0) {
        int diff = (a[i--] - '0') - (j >= 0 ? b[j--] - '0' : 0) - borrow;
        borrow = (diff < 0);
        result += (diff + (borrow ? 10 : 0)) + '0';
    }
    while (result.size() > 1 && result.back() == '0') result.pop_back();
    
    std::reverse(result.begin(), result.end());
    return result;
}

std::string sub_or_add(std::string a, std::string b) {
    bool negA = (a[0] == '-'), negB = (b[0] == '-');
    if (negA) a = a.substr(1);
    if (negB) b = b.substr(1);

    std::string result = (negA == negB) ? add(a, b) : sub(a, b);
    return (negA && negB) ? '-' + result : result;
}

bool compare(const std::string& num1, const std::string& num2) {
    if (num1[0] == '-' && num2[0] != '-') return false;
    if (num1[0] != '-' && num2[0] == '-') return true;
    
    bool negative = (num1[0] == '-');
    std::string abs1 = negative ? num1.substr(1) : num1;
    std::string abs2 = negative ? num2.substr(1) : num2;

    if (abs1.size() != abs2.size()) 
        return negative ? abs1.size() < abs2.size() : abs1.size() > abs2.size();

    return negative ? abs1 < abs2 : abs1 > abs2;
}

int main() {
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        std::string a, b, c;
        std::cin >> a >> b >> c;
        printf("Case #%d: %s\n", i, compare(sub_or_add(a, b), c) ? "true" : "false");
    }
}
