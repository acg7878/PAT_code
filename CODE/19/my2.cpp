#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
std::vector<int> convert(int num, int base) {
  std::vector<int> result;
  while (num > 0) {
    result.push_back(num % base);
    num /= base;
  }
  std::reverse(result.begin(), result.end());
  return result;
}

bool isPalic(std::vector<int>& num) {
  int left = 0;
  int right = num.size()-1;
  while (left < right) {
    if (num[left] != num[right]) {
      return false;
    }
    right--;
    left++;
  }
  return true;
}

int main() {
  int num, base;
  std::cin >> num >> base;
  std::vector<int> ans = convert(num, base);
  std::cout << (isPalic(ans) ? "Yes" : "No") << std::endl;
  for (size_t i = 0; i < ans.size(); i++) {
    std::cout << ans[i];
    if (i < ans.size() - 1)
      std::cout << " ";
  }
  std::cout << std::endl;
}