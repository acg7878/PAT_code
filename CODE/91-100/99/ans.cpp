#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int left, right;  // 存储左右子节点的索引
    int value;        // 存储当前节点的值
};

vector<TreeNode> tree;
vector<int> values;
int gobal_index = 0;  // 用于按中序遍历填充 BST 值

// 中序遍历填充 BST
void inorderFill(int root) {
    if (root == -1)
        return;
    inorderFill(tree[root].left);              // 递归左子树
    tree[root].value = values[gobal_index++];  // 按中序填充值
    inorderFill(tree[root].right);             // 递归右子树
}

// 层序遍历 BFS
void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    bool first = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (!first)
            cout << " ";
        cout << tree[node].value;
        first = false;

        if (tree[node].left != -1)
            q.push(tree[node].left);
        if (tree[node].right != -1)
            q.push(tree[node].right);
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    tree.resize(N);
    values.resize(N);

    // 读取二叉树结构
    for (int i = 0; i < N; i++) {
        cin >> tree[i].left >> tree[i].right;
    }

    // 读取要填充的值
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    // 排序以构造 BST
    sort(values.begin(), values.end());

    // 用中序遍历填充 BST
    inorderFill(0);

    // 层序遍历输出
    levelOrder(0);

    return 0;
}
