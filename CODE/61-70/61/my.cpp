#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> four_str(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> four_str[i];
    }
    std::vector<std::string> week = {"MON", "TUE", "WED", "THU",
                                     "FRI", "SAT", "SUN"};

    int len1 = std::min(four_str[0].size(), four_str[1].size());
    int len2 = std::min(four_str[2].size(), four_str[3].size());
    int day = -1, hour = -1, minute = -1;

    for (int i = 0; i < len1; i++) {
        if (four_str[0][i] == four_str[1][i]) {
            if (day == -1 && four_str[0][i] >= 'A' && four_str[0][i] <= 'G') {
                day = four_str[0][i] - 'A';
                std::cout << week[day] << " ";
            } else if (day != -1) {
                if (four_str[0][i] >= '0' && four_str[0][i] <= '9')
                    hour = four_str[0][i] - '0';
                else if (four_str[0][i] >= 'A' && four_str[0][i] <= 'N')
                    hour = four_str[0][i] - 'A' + 10;
                if (hour != -1) break;
            }
        }
    }

    for(int i=0;i<len2;i++){
        if(four_str[2][i] == four_str[3][i] && std::isalpha(four_str[2][i])){
            minute = i;
            break;
        }
    }
    printf("%02d:%02d\n",hour,minute);
}