#include <iostream>
#include <string>

using namespace std;

int main() {
    string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    int len1 = min(s1.length(), s2.length());
    int len2 = min(s3.length(), s4.length());
    
    int day = -1, hour = -1, minute = -1;
    
    // 解析星期几和小时
    for (int i = 0; i < len1; i++) {
        if (s1[i] == s2[i]) {
            if (day == -1 && s1[i] >= 'A' && s1[i] <= 'G') {
                day = s1[i] - 'A';
                continue;
            }
            if (day != -1) {
                if (s1[i] >= '0' && s1[i] <= '9') {
                    hour = s1[i] - '0';
                } else if (s1[i] >= 'A' && s1[i] <= 'N') {
                    hour = s1[i] - 'A' + 10;
                }
                if (hour != -1) break;
            }
        }
    }

    // 解析分钟
    for (int i = 0; i < len2; i++) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            minute = i;
            break;
        }
    }

    cout << week[day] << " ";
    printf("%02d:%02d\n", hour, minute);

    return 0;
}
