#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
std::vector<std::vector<int>> graph;
std::vector<int> temp;
std::set<int> s;
bool visit[10010];
int max_height;

void dfs(int node,int height){
    if(height > max_height){
        temp.clear();
        temp.push_back(node);
        max_height = height;
    }
    else if (max_height == height) {
        temp.push_back(node);
    }
    visit[node] = true;
    for (size_t i=0;i<graph[node].size();i++) {
        if(visit[graph[node][i]] == false){
            dfs(graph[node][i], height+1);
        }
    }
}

int main(){
    int n,cnt=0;
    std::cin >> n;
    graph.resize(n+1);
    for(int i=0;i<n-1;i++){
        int node1,node2;
        std::cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    int s1=0;
    for(int i=1;i<=n;i++){
        if(visit[i]  == false){
            dfs(i, 1);
            if(i == 1){
                if (temp.size() != 0) s1=temp[0];
                for(size_t j=0;j<temp.size();j++){
                    s.insert(temp[j]);
                }
            }
            cnt++;
        }  
    }

    if(cnt>=2){
        std::cout << "Error: " << cnt << " components\n";
    }else {
        temp.clear();
        max_height = 0;
        std::fill(visit,visit+10010,false);
        dfs(s1, 1);
        for (size_t i=0; i<temp.size(); i++) {
            s.insert(temp[i]);
        }
        for(auto it=s.begin();it!=s.end();it++){
            std::cout << *it << std::endl;
        }
    }
    return 0;
}
