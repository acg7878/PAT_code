#include <iostream>
#include <vector>
int main(){
    int n,m;
    std::cin >> n;
    std::vector<int> a1(n);
    for(int i=0;i<n;i++){
        std::cin >> a1[i];
    }
    std::cin >> m;
    std::vector<int> a2(m);
    for(int i=0;i<m;i++){
        std::cin >> a2[i];
    }
    int i=0,j=0,cnt=0;
    int target_index = (n+m+1)/2;
    int ans;
    while (i < n && j < m) {
        if(a1[i]<=a2[j]){
            ans = a1[i++];
        }else if (a1[i] > a2[j]) {
            ans = a2[j++];
        }
        if (++cnt == target_index) {
            break;
        }
    }
    while (i < n && cnt < target_index) {
        ans = a1[i++];
        if (++cnt == target_index) {
            break;
        }
        
    }
    while (j < m && cnt < target_index) {
        ans = a2[j++];
        if (++cnt == target_index) {
            break;
        }   
    }
    std::cout << ans << std::endl;
}