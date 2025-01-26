#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string original;
    cin >> original;

    // 翻倍的过程中直接处理字符串
    string doubled = "";
    int carry = 0;

    // 从最低位到最高位逐位计算翻倍结果
    for (int i = original.length() - 1; i >= 0; --i) {
        int digit = original[i] - '0'; // 将字符转换为数字
        int result = digit * 2 + carry; // 乘以2并加上进位
        doubled += (result % 10) + '0'; // 当前位结果
        carry = result / 10;           // 更新进位
    }
    if (carry > 0) {
        doubled += carry + '0'; // 如果最高位有进位，添加到结果
    }

    // 翻转字符串，得到正确的翻倍结果
    reverse(doubled.begin(), doubled.end());

    // 检查翻倍后长度是否与原始数字相同
    if (doubled.length() != original.length()) {
        cout << "No" << endl;
        cout << doubled << endl;
        return 0;
    }

    // 排序原始数字和翻倍后的数字
    string sorted_original = original;
    string sorted_doubled = doubled;
    sort(sorted_original.begin(), sorted_original.end());
    sort(sorted_doubled.begin(), sorted_doubled.end());

    // 比较排序后的结果
    if (sorted_original == sorted_doubled) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << doubled << endl;

    return 0;
}
