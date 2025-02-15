#include <iostream>
using namespace std;

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i;

    // 找到第一个相同的大写字母（A-G），确定星期
    for (i = 0; i < s1.length() && i < s2.length(); i++) {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
            cout << week[s1[i] - 'A'] << " ";
            break;
        }
    }

    // 找到下一个匹配字符（0-9 或 A-N），确定小时
    for (i++; i < s1.length() && i < s2.length(); i++) {
        if (s1[i] == s2[i]) {
            if (s1[i] >= '0' && s1[i] <= '9') {
                printf("%02d:", s1[i] - '0');  // '0' - '0' = 0, '9' - '0' = 9
                break;
            } else if (s1[i] >= 'A' && s1[i] <= 'N') {
                printf("%02d:", s1[i] - 'A' + 10);  // 'A' = 10, 'N' = 23
                break;
            }
        }
    }

    // 找到第一个相同的英文字母（a-z 或 A-Z），确定分钟
    for (i = 0; i < s3.length() && i < s4.length(); i++) {
        if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))) {
            printf("%02d\n", i);  // 直接用索引作为分钟数
            break;
        }
    }

    return 0;
}
