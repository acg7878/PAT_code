#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Person {
    std::string id;
    int virtue_grade;
    int talent_grade;
    int label;  // sage:3,nobleman:2,fool_man:1,small_man:0
};

bool cmp(Person& a, Person& b) {
    int total_a = a.talent_grade + a.virtue_grade;
    int total_b = b.talent_grade + b.virtue_grade;
    return a.label != b.label
               ? a.label > b.label
               : (total_a != total_b ? total_a > total_b
                                     : (a.virtue_grade != b.virtue_grade
                                            ? a.virtue_grade > b.virtue_grade
                                            : a.id < b.id));
}

int main() {
    int n, l, h;
    std::cin >> n >> l >> h;
    std::vector<Person> persons;
    for (int i = 0; i < n; i++) {
        std::string temp_id;
        int temp_virtue, temp_talent, temp_label;
        std::cin >> temp_id >> temp_virtue >> temp_talent;
        if (temp_virtue >= l && temp_talent >= l) {
            if (temp_virtue >= h && temp_talent >= h) {
                temp_label = 3;
            } else if (temp_virtue >= h && temp_talent < h) {
                temp_label = 2;
            } else if (temp_virtue >= temp_talent) {
                temp_label = 1;
            } else {
                temp_label = 0;
            }
            persons.push_back(
                Person(temp_id, temp_virtue, temp_talent, temp_label));
        }
    }
    std::sort(persons.begin(), persons.end(), cmp);
    std::cout << persons.size() << std::endl;
    for (auto& person : persons) {
        std::cout << person.id << " " << person.virtue_grade << " "
                  << person.talent_grade << std::endl;
    }
}