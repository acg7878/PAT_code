// 注意审题，题目给了范围在long long 之内所以没必要上高精度，纯纯浪费时间



#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; ++i) {
        long long A, B, C;
        cin >> A >> B >> C;
        
        // 检测A + B是否大于C，注意防止溢出
        bool result;
        if (A > 0 && B > 0 && A > LLONG_MAX - B) {
            result = true;  // 正溢出，A + B 必然大于 C
        } else if (A < 0 && B < 0 && A < LLONG_MIN - B) {
            result = false; // 负溢出，A + B 必然小于 C
        } else {
            result = (A + B > C);
        }

        cout << "Case #" << i << ": " << (result ? "true" : "false") << "\n";
    }
    
    return 0;
}
