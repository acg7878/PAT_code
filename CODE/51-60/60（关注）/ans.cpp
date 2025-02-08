#include <iostream>
#include <string>

using namespace std;

// pair:底数，指数
pair<string, int> toStandardForm(string num, int N) {
    // 去除前导零
    while (!num.empty() && num[0] == '0') {
        num.erase(0, 1);
    }
    // 处理空字符串（全部是0的情况）
    if (num.empty() || num == ".")
        return {"0." + string(N, '0'), 0};

    // 如果没有小数点，则加上
    if (num.find('.') == string::npos) {
        num += ".";
    }

    // 重新找小数点的位置
    int dotPos = num.find('.');

    // 找到第一个非零数字
    int firstNonZero = 0;
    while (firstNonZero < num.size() &&
           (num[firstNonZero] == '0' || num[firstNonZero] == '.')) {
        firstNonZero++;
    }
    // 计算指数
    int exponent = 0;
    if (firstNonZero == num.size()) {
        // 说明是 "0.000000" 这种情况
        return {"0." + string(N, '0'), 0};
    } else if (firstNonZero < dotPos) {
        exponent = dotPos - firstNonZero;
    } else {
        exponent = dotPos - firstNonZero + 1;
    }
    // 构造有效数字部分
    string mantissa;
    int count = 0;
    for (int i = firstNonZero; i < num.size() && count < N; ++i) {
        if (num[i] != '.') {
            mantissa += num[i];
            count++;
        }
    }
    // 补零
    while (mantissa.length() < N) {
        mantissa += '0';
    }
    return {"0." + mantissa, exponent};
}

int main() {
    int N;
    string A, B;
    cin >> N >> A >> B;

    auto [mantissaA, expA] = toStandardForm(A, N);
    auto [mantissaB, expB] = toStandardForm(B, N);

    if (mantissaA == mantissaB && expA == expB) {
        cout << "YES " << mantissaA << "*10^" << expA << endl;
    } else {
        cout << "NO " << mantissaA << "*10^" << expA << " " << mantissaB
             << "*10^" << expB << endl;
    }

    return 0;
}
