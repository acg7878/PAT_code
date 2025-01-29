#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
struct Station {
    double price,dist;
};
bool cmp(Station& a,Station& b){
    return a.dist < b.dist;
}
int main(){
    double cmax, d, davg;
    int n;
    std::cin >> cmax >> d >> davg >> n;
    std::vector<Station> sta(n+1);
    sta[0] = {0.0,d};
    for(int i=1;i<=n;i++){
        std::cin >> sta[i].price >> sta[i].dist;
    }
    std::sort(sta.begin(),sta.end(),cmp);
    double nowdis=0.0, maxdis=0.0, nowPrice = 0.0, total_cost = 0.0, left_dis = 0.0;
    if(sta[0].dist !=0){
        std::cout << "The maximum travel distance = 0.00\n";
        return 0;
    }else {
        nowPrice = sta[0].price;
    }

    while (nowdis < d) {
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = std::numeric_limits<int>::max();
        int flag = 0;
        for(int i=1;i<=n && sta[i].dist <= maxdis; i++){
            if(sta[i].dist <= nowdis) continue;
            
        }
    }
}