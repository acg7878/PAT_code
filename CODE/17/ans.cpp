#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct People {
    int come, time;
};

bool cmp(const People &a, const People &b) {
    return a.come < b.come;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<People> peoples;
    cin.ignore(); // 忽略前一个输入后的换行符

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int hh, mm, ss_time, tt;
        char colon;
        ss >> hh >> colon >> mm >> colon >> ss_time >> tt;
        int sum = hh * 3600 + mm * 60 + ss_time;
        if (sum > 61200) continue; // 忽略超过 17:00:00 的时间
        People people;
        people.come = sum;
        people.time = tt * 60;
        peoples.push_back(people);
    }

    sort(peoples.begin(), peoples.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; ++i) q.push(28800); // 初始化 k 个窗口，开始时间为 08:00:00

    int total = 0;
    int cnt = peoples.size();
    for (int i = 0; i < cnt; ++i) {
        if (q.top() <= peoples[i].come) {
            q.push(peoples[i].come + peoples[i].time);
            q.pop();
        } else {
            total += q.top() - peoples[i].come;
            q.push(q.top() + peoples[i].time);
            q.pop();
        }
    }

    if (cnt == 0) {
        printf("0.0\n");
    } else {
        printf("%.1lf\n", ((double)total / 60.0) / (double)cnt);
    }

    return 0;
}