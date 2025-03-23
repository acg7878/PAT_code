#include <iostream>
#include <string>
#include <unordered_set>
int main(){
    std::string s1,s2;
    std::getline(std::cin,s1);
    std::getline(std::cin,s2);

    std::unordered_set<char> s2_set;
    for(char c : s2) {
        s2_set.insert(c);
    }
    std::string result = "";
    for(char c : s1) {
        if(s2_set.find(c) == s2_set.end()) {
            result+=c;
        }
    }
    std::cout << result << std::endl;
}