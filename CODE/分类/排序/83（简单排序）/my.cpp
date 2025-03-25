#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string id;
    std::string name;
    int grade;
};

int main() {
    int N;
    std::cin >> N;
    std::vector<Student> students(N);
    for (int i = 0; i < N; i++) {
        std::cin >> students[i].name >> students[i].id >> students[i].grade;
    }
    int grade1, grade2;
    std::cin >> grade1 >> grade2;
    std::sort(students.begin(), students.end(),
              [](Student& a, Student& b) { return a.grade > b.grade; });
    bool isEmpty = true;
    for (auto& student : students) {
        if (student.grade >= grade1 && student.grade <= grade2) {
            isEmpty = false;
            std::cout << student.name << " " << student.id << std::endl;
        }
    }
    if(isEmpty) std::cout << "NONE" << std::endl;
    return 0;
}