#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// set拖慢了速度，时刻维护顺序，不如直接在输出的时候sort一下

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<std::string>> course(K + 1);

    while (N--) {
        std::string student;
        int course_num;
        std::cin >> student >> course_num;
        while (course_num--) {
            int course_index;
            std::cin >> course_index;
            course[course_index].push_back(student);
        }
    }

    for (int i = 1; i <= K; i++) {
        std::cout << i << " " << course[i].size() << '\n';
        std::sort(course[i].begin(), course[i].end());
        for (const auto &name : course[i]) {
            std::cout << name << '\n';
        }
    }

    return 0;
}
