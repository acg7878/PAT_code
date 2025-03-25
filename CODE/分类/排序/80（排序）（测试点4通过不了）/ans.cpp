#include <algorithm>
#include <iostream>
#include <vector>

// 定义学生结构体
struct Student {
    int id;
    int geScore;
    int giScore;
    int totalScore;
    std::vector<int> choices;
};

// 比较函数，按总分和入学考试成绩排序
bool cmpByScore(const Student& a, const Student& b) {
    if (a.totalScore != b.totalScore) {
        return a.totalScore > b.totalScore;
    }
    return a.geScore > b.geScore;
}

// 比较函数，按学生 ID 排序
bool cmpById(const Student& a, const Student& b) {
    return a.id < b.id;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> quotas(m);
    std::vector<int> counts(m, 0);
    std::vector<Student> students(n);
    std::vector<std::vector<Student>> schools(m);

    // 读取每个学校的招生名额
    for (int i = 0; i < m; ++i) {
        std::cin >> quotas[i];
    }

    // 读取每个学生的成绩和选择
    for (int i = 0; i < n; ++i) {
        students[i].id = i;
        std::cin >> students[i].geScore >> students[i].giScore;
        students[i].totalScore = students[i].geScore + students[i].giScore;
        students[i].choices.resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> students[i].choices[j];
        }
    }

    // 按总分和入学考试成绩对学生进行排序
    std::sort(students.begin(), students.end(), cmpByScore);

    // 处理每个学生的学校选择
    for (const auto& student : students) {
        for (int choice : student.choices) {
            int lastIndex = counts[choice] - 1; 
            if (counts[choice] < quotas[choice] ||
                (student.totalScore == schools[choice][lastIndex].totalScore &&
                 student.geScore == schools[choice][lastIndex].geScore)) {
                schools[choice].push_back(student);
                ++counts[choice];
                break;
            }
        }
    }

    // 输出每个学校录取的学生 ID
    for (int i = 0; i < m; ++i) {
        std::sort(schools[i].begin(), schools[i].end(), cmpById);
        for (int j = 0; j < counts[i]; ++j) {
            if (j != 0) {
                std::cout << " ";
            }
            std::cout << schools[i][j].id;
        }
        std::cout << std::endl;
    }

    return 0;
}