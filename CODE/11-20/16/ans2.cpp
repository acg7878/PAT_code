#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
    string name;
    int status, month, time, day, hour, minute;
};

// 比较函数：优先按用户名排序，相同用户名按时间排序
bool cmp(const Record& a, const Record& b) {
    return (a.name != b.name) ? (a.name < b.name) : (a.time < b.time);
}

// 计算从 00:00 到 `call` 时刻的总费用
double billFromZero(const Record& call, int *rate) {
    double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
    for (int i = 0; i < call.hour; i++) {
        total += rate[i] * 60;
    }
    return total / 100.0;
}

int main() {
    int rate[25] = {0};  // 费率表，rate[0]~rate[23]表示每小时的费率，rate[24]存储整天的总费用
    int n;  // 通话记录数
    string line;

    // 读取费率数据
    for (int i = 0; i < 24; i++) {
        cin >> rate[i];
        rate[24] += rate[i];  // 累加计算全天费率
    }

    // 读取通话记录
    cin >> n;  // 读取 n 的值

    vector<Record> records(n);

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);

        string statusStr;
        char colon; // 用于跳过 ":"

        ss >> records[i].name >> records[i].month >> colon 
           >> records[i].day >> colon >> records[i].hour 
           >> colon >> records[i].minute >> statusStr;

        records[i].status = (statusStr == "on-line") ? 1 : 0;
        records[i].time = records[i].day * 24 * 60 + records[i].hour * 60 + records[i].minute;
    }

    // 按照用户名和时间排序
    sort(records.begin(), records.end(), cmp);

    // 处理匹配的 on-line / off-line 记录
    map<string, vector<Record>> customers;
    for (int i = 1; i < n; i++) {
        if (records[i].name == records[i - 1].name && 
            records[i - 1].status == 1 && records[i].status == 0) {
            customers[records[i - 1].name].push_back(records[i - 1]);
            customers[records[i].name].push_back(records[i]);
        }
    }

    // 输出账单
    for (const auto& it : customers) {
        vector<Record> calls = it.second;
        cout << it.first;  // 输出用户名
        printf(" %02d\n", calls[0].month);  // 输出月份

        double total = 0.0;
        for (size_t i = 1; i < calls.size(); i += 2) {
            double cost = billFromZero(calls[i], rate) - billFromZero(calls[i - 1], rate);
            
            // 输出单次通话信息
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                   calls[i - 1].day, calls[i - 1].hour, calls[i - 1].minute,
                   calls[i].day, calls[i].hour, calls[i].minute,
                   calls[i].time - calls[i - 1].time, cost);

            total += cost;
        }

        // 输出总费用
        printf("Total amount: $%.2f\n", total);
    }

    return 0;
}
