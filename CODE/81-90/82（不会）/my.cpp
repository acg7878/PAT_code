#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<int, std::string> units = {
    {2, "Shi"},     {3, "Bai"},     {4, "Qian"},     {5, "Wan"},
    {6, "Shi"}, {7, "Bai"}, {8, "Qian"}, {9, "Yi"},
    {10, "Shi"}, {11, "Bai"}, {12, "Qian"}};
std::unordered_map<char, std::string> numberToStr = {
    {'0', "ling"}, {'1', "yi"},  {'2', "er"}, {'3', "san"}, {'4', "si"},
    {'5', "wu"},   {'6', "liu"}, {'7', "qi"}, {'8', "ba"},  {'9', "jiu"}};

int main() {
    std::string number;
    std::cin >> number;
    std::vector<std::string> result;
    if (number[0] == '-') {
        result.push_back("Fu");
        number = number.substr(1);
    }
    for (size_t i = 0; i < number.size(); i++) {
        if (number[i] == '0') { 
            int flag = number.size()-i;
            while (number[i] == '0' && i < number.size()) {
                i++;
            }
            
            i--;
            if (i != number.size()-1)
                result.push_back("ling");
        } else {
            result.push_back(numberToStr[number[i]]);
            if (i != number.size() - 1)
                result.push_back(units[number.size() - i]);
        }
    }
    for (size_t i = 0; i < result.size(); i++) {
        if (i != 0)
            std::cout << " ";
        std::cout << result[i];
    }
    std::cout << std::endl;
}