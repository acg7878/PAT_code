#include <iostream>
using namespace std;
string toMarsColor(int value) {
    const char digits[] = "0123456789ABC"; // 13进制字符
    string result;
    result += digits[value / 13]; // 获取高位，甚至能补0🤔
    result += digits[value % 13]; // 获取低位
    return result;
}
int main() {
    int r, g, b;
    cin >> r >> g >> b;
    string marsR = toMarsColor(r);
    string marsG = toMarsColor(g);
    string marsB = toMarsColor(b);
    cout << "#" << marsR << marsG << marsB << endl;
    return 0;
}
