#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Term {
    int exponent;
    double coefficient;
};

std::vector<Term> readPolynomial() {
    int K;
    std::cin >> K;
    std::vector<Term> polynomial(K);
    for (int i = 0; i < K; i++) {
        std::cin >> polynomial[i].exponent >> polynomial[i].coefficient;
    }
    return polynomial;
}

std::vector<Term> addPolynomials(const std::vector<Term>& A, const std::vector<Term>& B) {
    std::vector<Term> result;
    int i = 0, j = 0;
    
    while (i < A.size() && j < B.size()) {
        if (A[i].exponent > B[j].exponent) {
            result.push_back(A[i++]);
        } else if (A[i].exponent < B[j].exponent) {
            result.push_back(B[j++]);
        } else {
            double sum = A[i].coefficient + B[j].coefficient;
            if (sum != 0) {
                result.push_back({A[i].exponent, sum});
            }
            i++; j++;
        }
    }
    
    while (i < A.size()) result.push_back(A[i++]);
    while (j < B.size()) result.push_back(B[j++]);
    
    return result;
}

int main() {
    std::vector<Term> A = readPolynomial();
    std::vector<Term> B = readPolynomial();
    
    std::vector<Term> sum = addPolynomials(A, B);
    
    std::cout << sum.size();
    for (const auto& term : sum) {
        std::cout << " " << term.exponent << " " << std::fixed << std::setprecision(1) << term.coefficient;
    }
    std::cout << std::endl;
    
    return 0;
}