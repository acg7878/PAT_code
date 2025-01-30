#include <iostream>
#include <sstream>
#include <string>

struct Money {
    int Galleon,Sickle,Knut;
};

int main(){
    Money money1,money2,money3={0,0,0};
    std::string line;
    std::getline(std::cin,line);
    std::stringstream ss(line);
    char colon;
    ss >> money1.Galleon >> colon >> money1.Sickle >> colon >> money1.Knut;
    ss >> money2.Galleon >> colon >> money2.Sickle >> colon >> money2.Knut;
    int Sickle_carry = 0,Galleon_carry = 0;
    money3.Knut = (money1.Knut + money2.Knut)%29;
    Sickle_carry = (money1.Knut + money2.Knut)/29;
    money3.Sickle = (money1.Sickle + money2.Sickle + Sickle_carry)%17;
    Galleon_carry = (money1.Sickle + money2.Sickle + Sickle_carry)/17;
    money3.Galleon = money1.Galleon + money2.Galleon + Galleon_carry;
    std::cout << money3.Galleon<<"."<<money3.Sickle<<"."<<money3.Knut << std::endl;
}