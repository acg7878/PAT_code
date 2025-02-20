#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// 辅助函数：将字符串按非字母数字字符分割成单词
std::vector<std::string> split(const std::string& s) {
    std::vector<std::string> result;
    std::string word;
    for (char c : s) {
        if (std::isalnum(c)) {
            word += c;
        } else if (!word.empty()) {
            result.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        result.push_back(word);
    }
    return result;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::vector<std::string> words = split(str);
    std::map<std::string, int> words_count;
    for (const auto& word : words) {
        std::string lower_word = word;
        std::transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);
        words_count[lower_word]++;
    }

    int max_count = -1;
    std::string max_word;
    for (const auto& pair : words_count) {
        if (pair.second > max_count) {
            max_count = pair.second;
            max_word = pair.first;
        } else if (pair.second == max_count && pair.first < max_word) {
            max_word = pair.first;
        }
    }

    std::cout << max_word << " " << max_count << std::endl;

    return 0;
}