#include <iostream>
#include <string>
#include <vector>
int main() {
    std::vector<int> stack;
    std::vector<std::string> ans;
    int n;
    std::cin >> n;
    while (n--) {
        std::string command;
        std::cin >> command;
        if (command == "Push") {
            int key;
            std::cin >> key;
            stack.push_back(key);
            //std::cout << key << std::endl;
            //ans.push_back(std::to_string(key));
        } else if (command == "Pop") {
            if (stack.empty()) {
                //std::cout << "Invalid" << std::endl;
                ans.push_back("Invalid");
            } else {
                // std::cout << stack[stack.size()-1] << std::endl;
                ans.push_back(std::to_string(stack[stack.size() - 1]));
                stack.pop_back();
            }
        } else if (command == "PeekMedian") {
            int index = (stack.size()) / 2;
            if (stack.empty()) {
                // std::cout << "Invalid" << std::endl;
                ans.push_back("Invalid");
            } else  //std::cout << stack[index] << std::endl;
                ans.push_back(std::to_string(stack[index]));
        }
    }
    for (std::string str : ans) {
        std::cout << str << std::endl;
    }
}