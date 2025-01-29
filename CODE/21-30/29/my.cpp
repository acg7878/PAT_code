#include <algorithm>
#include <iostream>
#include <vector>
int main(){
    std::vector<long int> vec;
    for(int i=0;i<2;i++){
        int n;
        std::cin >> n;
        while (n--) {
            long int x;
            std::cin >> x;
            vec.push_back(x);
        }
    }
    std::sort(vec.begin(),vec.end());
    std::cout << vec[vec.size()/2] << std::endl;
}