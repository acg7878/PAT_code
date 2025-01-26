#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
int main() {
  std::string origin;
  std::cin >> origin;

  std::string doubled = "";
  int carry = 0;
  for (int i = origin.size() - 1; i >= 0; i--) {
    int digit = origin[i] - '0';
    int result = digit * 2 + carry;
    doubled += (result % 10) + '0';
    carry = result / 10;
  }
  if (carry > 0) {
    doubled += carry + '0';
  }
  std::reverse(doubled.begin(), doubled.end());
  std::string sorted_origin = origin;
  std::string sorted_doubled = doubled;

  std::sort(sorted_origin.begin(), sorted_origin.end());
  std::sort(sorted_doubled.begin(), sorted_doubled.end());

  if (sorted_doubled == sorted_origin) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  std::cout << doubled << std::endl;
}