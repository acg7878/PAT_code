#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
std::string findLongestCommonSuffix(const std::vector<std::string>& lines) {
    std::string result = lines[0];
    for (int i = 1; i < lines.size(); i++) {
        std::string cur_str = lines[i];
        if (result.back() != cur_str.back())
            return "nai";
        int j = 0;
        while (j < std::min(result.size(), cur_str.size()) &&
               result[result.size() - 1 - j] ==
                   cur_str[cur_str.size() - 1 - j]) {
            j++;
        }
        result = result.substr(result.size() - j, j);
    }
    return result.empty() ? "nai" : result;
}
int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    std::vector<std::string> lines(N);
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, lines[i]);
    }
    std::string result = findLongestCommonSuffix(lines);
    std::cout << result << std::endl;
}