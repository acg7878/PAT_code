

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
struct TreeNode {
  int left, right;
  int value;
};
std::vector<int> value;
std::vector<TreeNode> tree;
int m_index = 0;


void createTree(int root) {
  if (root == -1)
    return;

  createTree(tree[root].left);
  tree[root].value = value[m_index++];
  createTree(tree[root].right);
}

void levelOrder(int root) {
  std::queue<int> q;
  q.push(root);

  bool first = true;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (!first)
      std::cout << " ";
    std::cout << tree[node].value;
    first = false;

    if (tree[node].left != -1)
      q.push(tree[node].left);
    if (tree[node].right != -1)
      q.push(tree[node].right);
  }
  std::cout << std::endl;
}

int main(){
    int N;
    std::cin >> N;
    tree.resize(N);
    value.resize(N);

    for(int i=0;i<N;i++){
        std::cin >> tree[i].left >> tree[i].right;
    }
    for(int i=0;i<N;i++){
        std::cin >> value[i];
    }
    std::sort(value.begin(),value.end());
    createTree(0);
    levelOrder(0);
    return 0;
}