#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
std::vector<std::string> split(const std::string& s) {
    std::vector<std::string> result;
    std::string word;
    for(char c : s) {
        if(std::isalnum(c)){
            word+=c;
        } else if(!word.empty()){
            result.push_back(word);
            word.clear();
        }
    }
    if(!word.empty())result.push_back(word);
    return result;
}

int main() {
    std::string str;
    std::getline(std::cin,str);
    std::vector<std::string> words = split(str);
    std::map<std::string, int> words_count;
    int max_count = -1;
    std::string max_word;
    for(const auto& word: words) {
        std::string lower_word = word;
        std::transform(lower_word.begin(),lower_word.end(),lower_word.begin(),::tolower);
        words_count[lower_word]++;
    }
    for(const auto& pair : words_count){
        if(pair.second > max_count) {
            max_count = pair.second;
            max_word = pair.first;
        } else if(max_count == pair.second && pair.first < max_word){
            max_word = pair.first;
        }
    }
    std::cout << max_word << " " << max_count << std::endl; 
}