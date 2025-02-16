#include <iostream>
#include <utility>
#include <vector>
int main(){
    int n;
    int zero_index = -1, count = 0;
    std::cin >> n;
    std::vector<int> vec(n);
    for(int i=0;i<n;i++) {
        std::cin >> vec[i];
        if(vec[i]==0) zero_index = i;
    }

    while (vec[0] != 0) {
        for(int i=0;i<n;i++){
            if(vec[i] == zero_index) {
                std::swap(vec[zero_index],vec[i]);
                zero_index = i;
                count++;
                break;
            }
        }
    }
}