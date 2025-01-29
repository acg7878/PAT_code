#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
long long convertDecimal(std::string num, long long radix) {
  long long sum = 0;
  int index = 0;
  for (auto it = num.rbegin(); it != num.rend(); it++) {
    long long temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
    sum += temp * pow(radix, index++);
  }
  return sum;
}

long long find_radix(std::string num, long long number) {
  char it = *std::max_element(num.begin(), num.end());
  long long low = isdigit(it) ? it - '0' : it - 'a' + 10;
  long long high = std::max(number, low);
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long temp = convertDecimal(num, mid);
    if (temp < 0 || temp > number)
      high = mid - 1;
    else if (temp == number)
      return mid;
    else
      low = mid + 1;
  }
  return -1;
}

int main() {
  std::string n1, n2;
  int tag;
  long long radix, result_radix;
  std::cin >> n1 >> n2 >> radix >> result_radix;
  result_radix = tag == 1 ? find_radix(n2, convertDecimal(n1, radix))
                          : find_radix(n1, convertDecimal(n2, radix));
  if (result_radix == -1) {
    std::cout << "Impossible" << std::endl;
  } else {
    std::cout << result_radix << std::endl;
  }
}