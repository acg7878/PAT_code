#include <iostream>
#include <string>
#include <vector>
#include <set>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N,K;
    std::cin >> N >> K;
    std::vector<std::set<std::string>> course(K+1);
    while (N--) {
        std::string student;
        int course_num;
        std::cin >> student >> course_num;
        while (course_num--) {
            int course_index;
            std::cin >> course_index;
            course[course_index].insert(student);
        }
    }
    for(int i=1;i<=K;i++) {
        std::cout << i << " " << course[i].size() << std::endl;
        for(const auto& name : course[i]) {
            std::cout << name << std::endl;
        }
    }
}