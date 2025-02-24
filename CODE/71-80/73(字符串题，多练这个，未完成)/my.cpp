#include <cstdlib>
#include <iostream>
#include <string>
int main(){
    std::string input;
    std::cin >> input;
    size_t ePos = input.find('E');
    std::string base = (input.substr(1,ePos-1));
    int exponent = std::stoi(input.substr(ePos+1));
    if(input[0]=='-') std::cout << "-";
    if(exponent<0){
        std::cout << "0.";
        for(int i=0;i<abs(exponent)-1;i++) std::cout << "0";
        for(char c : base) {
            if(c!='.')std::cout << c;
        }
    }
    else {
        std::cout << base[0];
        int move
    }
}