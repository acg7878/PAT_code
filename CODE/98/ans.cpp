#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
int n;

void next(std::vector<int> &vec, int low, int high) {
    int i=1,j=i*2;
    while(j<=high){
        if(j+1<=high && vec[j]<vec[j+1])j++;
        if(vec[i]>vec[j])break;
        std::swap(vec[i],vec[j]);
        i=j;j=i*2;
    }
}

int judge(std::vector<int> a, std::vector<int> &b) {
  int p = 2;
  while (p <= n && b[p - 1] <= b[p])
    p++;
  b[0] = p; // offset
  while (p <= n && a[p] == b[p])
    p++;
  if (p == n + 1)
    return 1; // 插入
  else
    return 2; // 堆
}

int main() {

  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++)
    std::cin >> a[i];
  for (int i = 1; i <= n; i++)
    std::cin >> b[i];
  if (judge(a, b) == 1) {
    std::cout << "Insertion Sort" << std::endl;
    std::sort(b.begin() + 1, b.begin() + b[0] + 1);
  } else {
    std::cout << "Heap Sort\n";
    int p = n;
    while (p > 2 && b[p] >= b[1])
      p--;
    std::swap(b[1], b[p]);
    next(b, 1, p - 1);
  }
  for(int i=1;i<=n;i++){
    if(i!=1){
        std::cout << " " << b[i]; 
    }else {
        std::cout << b[i];
    }
  }
  std::cout << "\n";
}