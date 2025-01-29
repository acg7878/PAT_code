#include <iostream>
#include <map>
#include <vector>

std::vector<int> post;
std::vector<int> in;
std::vector<int> pre;
std::map<int, int> level;
void preTree(int root,int start,int end,int index){
    if(start > end)return;
    int i = start;
    while (i<=end && post[root]!=in[i]) i++;
    //pre.push_back(post[root]);
    level[index] = post[root];
    preTree(root - (end - i) -1,start,i-1,2*index+1);
    preTree(root-1, i+1, end,2*index+2);

}


int main(){
    int n;
    std::cin >> n;
    post.resize(n);
    in.resize(n);
    for(int i=0;i<n;i++){
        std::cin >> post[i];
    }
    for (int i=0;i<n;i++) {
        std::cin >> in[i];
    }
    preTree(n-1, 0, n-1,0);
    for (auto it = level.begin(); it != level.end(); ++it) {
        std::cout << it->second;
        if (std::next(it) != level.end()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}