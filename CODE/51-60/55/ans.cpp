#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Person {
    std::string name;
    int age;
    int net_worth;
};

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<Person> persons(n);

    for (int i = 0; i < n; i++) {
        std::cin >> persons[i].name >> persons[i].age >> persons[i].net_worth;
    }

    // 排序规则：财富降序，年龄升序，姓名升序
    std::sort(
        persons.begin(), persons.end(), [](const Person& a, const Person& b) {
            return a.net_worth != b.net_worth
                       ? a.net_worth > b.net_worth
                       : (a.age != b.age ? a.age < b.age : a.name < b.name);
        });

    // 限制每个年龄最多存 100 人
    std::vector<Person> filtered;
    std::vector<int> age_count(205, 0);
    for (const auto& p : persons) {
        if (age_count[p.age] < 100) {
            filtered.push_back(p);
            age_count[p.age]++;
        }
    }

    // 处理查询
    for (int i = 1; i <= k; i++) {
        int m, amin, amax;
        std::cin >> m >> amin >> amax;

        std::vector<Person> result;
        std::cout << "Case #" << i << ":\n";

        // 筛选符合年龄范围的人员
        for (const auto& p : filtered) {
            if (p.age >= amin && p.age <= amax) {
                result.push_back(p);
                if ((int)result.size() >= m)
                    break;  // 提前终止
            }
        }

        if (result.empty()) {
            std::cout << "None\n";
        } else {
            for (const auto& p : result) {
                std::cout << p.name << " " << p.age << " " << p.net_worth
                          << "\n";
            }
        }
    }
}
