#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int left = 0, right = 0;
    int maxLength = 0;
    while (right < n) {
        if (nums[right] <= (long long)nums[left] * p) {
            maxLength = max(maxLength, right - left + 1);
            right++;
        } else {
            left++;
            if (left > right) {
                right = left;
            }
        }
    }
    cout << maxLength << endl;
    return 0;
}
