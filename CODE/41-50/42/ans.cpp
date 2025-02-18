#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string cards[54];

void initCards() {
    string suits[] = {"S", "H", "C", "D"};
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            ostringstream oss;
            oss << suits[i] << j;
            cards[i * 13 + j - 1] = oss.str();
        }
    }
    cards[52] = "J1";
    cards[53] = "J2";
}

int main() {
    initCards();
    int K;
    cin >> K;
    vector<int> order(54);
    for (int i = 0; i < 54; ++i) {
        cin >> order[i];
        order[i]--;
    }
    vector<string> temp(54);
    for (int k = 0; k < K; ++k) {
        for (int i = 0; i < 54; ++i) {
            temp[order[i]] = cards[i];
        }
        for (int i = 0; i < 54; ++i) {
            cards[i] = temp[i];
        }
    }
    for (int i = 0; i < 54; ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << cards[i];
    }
    return 0;
}