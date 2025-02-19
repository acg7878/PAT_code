#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
struct mookcake {
    double total_price;
    double amounts;
    double price;
    mookcake() : total_price(0.0), amounts(0.0), price(0.0){};
    mookcake(double x,  double y) : total_price(x), amounts(y), price(x / y) {};
};

int main() {
    int n, d;
    std::cin >> n >> d;
    std::cin.ignore();
    std::vector<mookcake> mooncakes;
    mooncakes.reserve(n);
    std::string line1, line2;
    std::getline(std::cin, line1);
    std::getline(std::cin, line2);
    std::stringstream ss1(line1);
    std::stringstream ss2(line2);
    double total_price,amount;
    while (ss1 >> amount && ss2 >> total_price) {
        mooncakes.push_back(mookcake(total_price, amount));
    }
    std::sort(mooncakes.begin(), mooncakes.end(), [](mookcake& a, mookcake& b) {
        return a.price > b.price;
    });
    double profit = 0.0,product = 0.0;
    int index = 0;
    while (product != d && index < n) {
        double margin = d - product;
        if (mooncakes[index].amounts <= margin) {
            product += mooncakes[index].amounts;
            profit += mooncakes[index].total_price;
        } else {
            product = d;
            profit += mooncakes[index].price * margin;
        }
        index++;
    }
    std::cout << std::fixed << std::setprecision(2) << profit << std::endl; 
}