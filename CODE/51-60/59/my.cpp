#include <iostream>
#include <vector>

const int LIMIT = 50000;

std::vector<int> getPrimeVec(int limit){
    std::vector<bool> is_prime(limit,true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i*i<limit;i++){
        if(is_prime[i]){
            for(int j=i*i;j<limit;j+=i){
                is_prime[j] = false;
            }
        }
    }
    std::vector<int> primes;
    for(int i=2;i<limit;i++){
        primes.push_back(i);
    }
    return primes;
}

void factorize(long long n,std::vector<int>& primes){
    std::cout << n<<"=";
    if(n==1){
        std::cout << 1 << std::endl;
        return;
    }
    bool first = true;
    for(int prime : primes) {
        if(prime * prime > n) break;
        int count = 0;
        while (n % prime == 0) {
            n /= prime;
            count++;
        }
        if(count > 0){
            if(!first)std::cout << "*";
            std::cout << prime;
            if(count > 1)std::cout << "^" << count;
            first = false;
            
        }
    }
    if(n>1){
        if (!first) {
            std::cout << "*";
        }
        std::cout << n;
    }
    std::cout << std::endl;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> primes = getPrimeVec(LIMIT);
    factorize(n, primes);
}