#include <iostream>
#include <limits>
#include <string>
struct Student {
    std::string name;
    std::string id;
    int grade;
};
int main(){
    int n;
    std::cin >> n;
    Student min_male = Student{"","",std::numeric_limits<int>::max()};
    Student max_female = Student{"","",std::numeric_limits<int>::min()};
    while (n--) {
        std::string gender,id,name;
        int grade;
        std::cin >> name >> gender >> id >> grade;
        if(gender == "F"){
            if(grade > max_female.grade){
                max_female = Student{name,id,grade};
            }
        }else {
            if (grade < min_male.grade) {
                min_male = Student{name,id,grade};
            }
        }
    }
    if(max_female.grade == std::numeric_limits<int>::min()){
        std::cout << "Absent" << std::endl;
    }else {
        std::cout << max_female.name << " " << max_female.id << std::endl;
    }
    if(min_male.grade == std::numeric_limits<int>::max()){
        std::cout << "Absent" << std::endl;
    }else {
        std::cout << min_male.name << " " << min_male.id << std::endl;
    }
    if(!(max_female.grade == std::numeric_limits<int>::min()) && !(min_male.grade == std::numeric_limits<int>::max())){
        std::cout << max_female.grade-min_male.grade << std::endl;
    }else {
        std::cout << "NA" << std::endl;
    }
}