#include <iostream>
#include <string>
#include <limits>

struct Student {
    std::string id;
    std::string name;
    int grade;
};

int main() {
    int n;
    std::cin >> n;

    Student max_female{"", "", std::numeric_limits<int>::min()};
    Student min_male{"", "", std::numeric_limits<int>::max()};

    for (int i = 0; i < n; ++i) {
        Student student;
        std::string gender;
        std::cin >> student.name >> gender >> student.id >> student.grade;

        if (gender == "F" && student.grade > max_female.grade) {
            max_female = student;
        } else if (gender == "M" && student.grade < min_male.grade) {
            min_male = student;
        }
    }

    if (max_female.grade == std::numeric_limits<int>::min())
        std::cout << "Absent" << std::endl;
    else
        std::cout << max_female.name << " " << max_female.id << std::endl;

    if (min_male.grade == std::numeric_limits<int>::max())
        std::cout << "Absent" << std::endl;
    else
        std::cout << min_male.name << " " << min_male.id << std::endl;

    if (max_female.grade != std::numeric_limits<int>::min() && min_male.grade != std::numeric_limits<int>::max())
        std::cout << max_female.grade - min_male.grade << std::endl;
    else
        std::cout << "NA" << std::endl;

    return 0;
}
