#include <cmath>
#include <iostream>
#include <vector>
bool isPrime(int num){
    if(num <= 1) return false;
    for(int i=2;i<=std::sqrt(num);i++) {
        if(num%i==0)return false;
    }
    return true;
}

int nextPrime(int num) {
    while (!isPrime(num)) {
        num++;
    }
    return num;
}

int main(){
    int MSize,N;
    std::cin >> MSize >> N;
    MSize = nextPrime(MSize);
    std::vector<int> hash_table(MSize,-1);

    int num;
    for(int i=0;i<N;i++){
        std::cin >> num;
        int pos = num % MSize;
        int origin_pos = pos;
        int step = 1;
        while (hash_table[pos] != -1) {
            pos = (origin_pos + step * step) % MSize;
            step++;
            if(step > MSize) {
                std::cout << "-";
                if(i != N-1) std::cout << " ";
                break;
            }
        }
        if(hash_table[pos] == -1) {
            hash_table[pos] = num;
            std::cout << pos;
            if(i != N-1) std::cout << " ";
            
        }
    }

}