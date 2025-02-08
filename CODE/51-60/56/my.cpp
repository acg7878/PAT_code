#include <algorithm>
#include <iostream>
#include <vector>
struct Mouce {
    int weight;
    int order;
    int rank;
    int first_order;
};

int main() {
    int Np, Ng;
    std::cin >> Np >> Ng;
    std::vector<Mouce> mice(Np);
    for (int i = 0; i < Np; i++){
        mice[i].first_order = i;
        std::cin >> mice[i].weight;
    }
    for (int i = 0; i < Np; i++)
        std::cin >> mice[i].order;
    std::sort(mice.begin(),mice.end(),[](const Mouce& a,const Mouce& b){
        return a.order < b.order;
    });
    std::vector<Mouce> ans; 
    for(int i=0;i<Np;i+=3){
        
    }
}