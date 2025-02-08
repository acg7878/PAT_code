#include <iostream>
#include <map>
int main() {
    int n,m;
    std::cin >> n >> m;
    std::map<int, int> colors; // color,count;
    int pixel = n*m;
    while (n--) {
        for(int i=0;i<m;i++){
            int temp;
            std::cin >> temp;
            colors[temp]++;
            if(colors[temp] > pixel/2){
                std::cout << temp << std::endl;
                return 0;
            }
        }
    }
}