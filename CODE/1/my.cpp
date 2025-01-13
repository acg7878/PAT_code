#include <iostream>
#include <string>
std::string formatNumber(long long num){
    std::string str = std::to_string(num);
    int insert_position = str.size()-3;
    while(insert_position>0 && (str[0]!='-' || insert_position>1)){
        str.insert(insert_position,",");
        insert_position-=3;
    }
    return str;
}
int main(){
    long long a,b;
    std::cin >> a >> b;
    long long result = a+b;
    std::cout << formatNumber(result) << std::endl;
}