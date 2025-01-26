// 处理不了太大的数字，应该该用字符串
// 算法太垃圾了，不如排序后对比


#include <iostream>
#include <vector>

std::vector<int> task(int num) {
  std::vector<int> vec;
  while (num > 0) {
    vec.push_back(num % 10);
    num /= 10;
  }
  return vec;
}

int main() {

  long long num;
  std::cin >> num;
  long long double_num = num * 2;
  long long temp = double_num;
  std::vector<int> origin = task(num);
  while (double_num > 0) {
    bool flag = false;
    int digit = double_num % 10;
    for (size_t i = 0; i < origin.size(); i++) {
      if (digit == origin[i]) {
        origin.erase(origin.begin() + i);
        flag = true;
      }
    }
    if (!flag) {
      std::cout << "No" << std::endl;
      std::cout << temp << std::endl;
      return 0;
    }
    double_num /= 10;
  }
  if (!origin.empty()) {
    std::cout << "No" << std::endl;
    std::cout << temp << std::endl;
    return 0;
  }

  std::cout << "Yes" << std::endl;
  std::cout << temp << std::endl;
}