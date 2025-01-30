#include <iostream>
#include <stack>
#include <vector>

#define lowbit(i) ((i) & (-(i)))

const int maxn = 100010;
using namespace std;

vector<int> c(maxn, 0);
stack<int> s;

void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += v;
    }
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

void PeekMedian() {
    int left = 1, right = maxn, mid;
    int k = (s.size() + 1) / 2;
    while (left < right) {
        mid = (left + right) / 2;
        if (getsum(mid) >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

int main() {
    int n, temp;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "Push") {  // "push"
            cin >> temp;
            s.push(temp);
            update(temp, 1);
        } else if (str == "Pop") {  // "pop"
            if (!s.empty()) {
                update(s.top(), -1);
                cout << s.top() << endl;
                s.pop();
            } else {
                cout << "Invalid" << endl;
            }
        } else {  // "peek"
            if (!s.empty()) {
                PeekMedian();
            } else {
                cout << "Invalid" << endl;
            }
        }
    }
    return 0;
}
