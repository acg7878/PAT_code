#include <iostream>
#include <vector>

using namespace std;

constexpr int LIMIT = 50000;

// 预处理素数表
vector<int> generatePrimes(int limit) {
    vector<bool> is_prime(limit, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i < limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// 质因数分解
void factorize(long long n, const vector<int>& primes) {
    cout << n << "=";

    if (n == 1) {
        cout << "1\n";
        return;
    }

    bool first = true;
    for (int prime : primes) {
        if (prime * prime > n)
            break;

        int count = 0;
        while (n % prime == 0) {
            n /= prime;
            count++;
        }

        if (count > 0) {
            if (!first)
                cout << "*";
            cout << prime;
            if (count > 1)
                cout << "^" << count;
            first = false;
        }
    }

    if (n > 1) {
        if (!first)
            cout << "*";
        cout << n;
    }
    cout << endl;
}

int main() {
    long long n;
    cin >> n;

    vector<int> primes = generatePrimes(LIMIT);
    factorize(n, primes);

    return 0;
}
