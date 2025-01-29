#include <iomanip>
#include <iostream>
#include <vector>
struct Node{
    char key;
    int next;
    bool isVisit;
};

int main() {
    int address1,address2,n;
    std::cin >> address1 >> address2 >> n;
    std::vector<Node> list(100005);
    while (n--) {
        int address,next;
        char key;
        std::cin >> address >> key >> next;
        list[address] = {key,next,false};
    }
    for(int i=address1;i!=-1;i=list[i].next){
        list[i].isVisit = true;
    }
    for(int i=address2;i!=-1;i=list[i].next){
        if(list[i].isVisit == true){
            std::cout << std::setw(5) << std::setfill('0') << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}