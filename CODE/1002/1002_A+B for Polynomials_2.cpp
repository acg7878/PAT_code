#include <iomanip>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Term {
    int exponents;
    double coefficients;
};

vector<Term> readPolynomial() {
    int K;
    cin >> K;
    vector<Term> polynomial(K);
    for (int i = 0; i < K; i++) {
        cin >> polynomial[i].exponents >> polynomial[i].coefficients;
    }
    return polynomial;
}

vector<Term> addPolynomials(const vector<Term> &A, const vector<Term> &B) {
    vector<Term> result;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i].exponents > B[j].exponents) {
            result.push_back(A[i++]);
        } else if (A[i].exponents < B[j].exponents) {
            result.push_back(B[j++]);
        } else {
            double sum = A[i].coefficients + B[j].coefficients;
            if (sum != 0) {
                result.push_back({A[i].exponents, sum});
            }
            i++, j++;
        }
    }

    while (i < A.size())
        result.push_back(A[i++]);
    while (j < B.size())
        result.push_back(B[j++]);

    return result;
}

int main(int argc, char const *argv[]) {
    vector<Term> A = readPolynomial();
    vector<Term> B = readPolynomial();

    vector<Term> ans = addPolynomials(A, B);
    cout << ans.size();
    for (int i = 0; i < ans.size(); i++) {
        cout << " " << ans[i].exponents << " " << fixed << setprecision(1)
             << ans[i].coefficients;
    }
    cout << endl;
    return 0;
}
