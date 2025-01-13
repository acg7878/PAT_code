#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// 表示1到12对应的火星文，用于个位数字
std::map<int, std::string> month = {
    {1,"jan"},{2,"feb"},{3,"mar"},{4,"apr"},{5,"may"},{6,"jun"},{7,"jly"},{8,"aug"},
    {9,"sep"},{10,"oct"},{11,"nov"},{12,"dec"}
};
// 表示高位数字（十位及以上对应的十三进制每一位的乘数情况）对应的火星文
std::map<int, std::string> high_month = {
    {1,"tam"},{2,"hel"},{3,"maa"},{4,"huh"},{5,"tou"},{6,"kes"},{7,"hei"},{8,"elo"},
    {9,"syy"},{10,"lok"},{11,"mer"},{12,"jou"}
};

// 将地球数字转换为火星数字的函数
std::string numTostr(std::string num) {
    int n = std::stoi(num);
    if (n == 0) return "tret";
    std::string result;
    int high = n / 13;
    int low = n % 13;
    if (high > 0) {
        result += high_month[high];
        if (low > 0) {
            result += " " + month[low];
        }
    }
    else {
        result += month[low];
    }
    return result;
}

// 将火星数字转换为地球数字的函数
int strTonum(std::string str) {
    std::vector<std::string> words;
    std::stringstream ss(str);
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }
    if (words.size() == 1) {
        if (words[0] == "tret") return 0;
        for (const auto& m : month) {
            if (m.second == words[0]) return m.first;
        }
        for (const auto& hm : high_month) {
            if (hm.second == words[0]) return hm.first * 13;
        }
    }
    else if (words.size() == 2) {
        int high = 0, low = 0;
        for (const auto& hm : high_month) {
            if (hm.second == words[0]) high = hm.first;
        }
        for (const auto& m : month) {
            if (m.second == words[1]) low = m.first;
        }
        return high * 13 + low;
    }
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::string line;
    std::getline(std::cin, line);  // 读取换行符，避免后续输入受影响
    while (n--) {
        std::getline(std::cin, line);
        if (std::isdigit(line[0])) {
            std::cout << numTostr(line) << std::endl;
        }
        else {
            std::cout << strTonum(line) << std::endl;
        }
    }
    return 0;
}