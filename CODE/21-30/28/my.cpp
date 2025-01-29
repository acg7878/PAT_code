#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string id;
    std::string name;
    int grade;
};

int n, c;

bool cmp(const Student &a, const Student &b) {
    return (c == 1) ? (a.id < b.id) :
           (c == 2) ? (a.name != b.name ? a.name < b.name : a.id < b.id) :
           (c == 3) ? (a.grade != b.grade ? a.grade < b.grade : a.id < b.id) :
           false;
}

int main() {
    std::cin >> n >> c;
    std::vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        std::cin >> students[i].id >> students[i].name >> students[i].grade;
    }
    std::sort(students.begin(), students.end(), cmp);

    for (const Student &student : students) {
        std::cout << student.id << " " << student.name << " " << student.grade << std::endl;
    }

    return 0;
}