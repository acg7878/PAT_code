#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 插入普通 BST
void insert(TreeNode*& root, int val) {
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->val)
        insert(root->left, val);
    else
        insert(root->right, val);
}

// 插入镜像 BST
void insertMirror(TreeNode*& root, int val) {
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    if (val >= root->val)
        insertMirror(root->left, val);
    else
        insertMirror(root->right, val);
}

// 前序遍历
void preorder(TreeNode* root, vector<int>& seq) {
    if (!root) return;
    seq.push_back(root->val);
    preorder(root->left, seq);
    preorder(root->right, seq);
}

// 后序遍历
void postorder(TreeNode* root, vector<int>& seq) {
    if (!root) return;
    postorder(root->left, seq);
    postorder(root->right, seq);
    seq.push_back(root->val);
}

int main() {
    int N;
    cin >> N;
    vector<int> input(N);
    for (int i = 0; i < N; i++) cin >> input[i];

    // 尝试构建 BST 和镜像 BST
    TreeNode* bst = nullptr;
    TreeNode* mirrorBST = nullptr;
    for (int val : input) {
        insert(bst, val);
        insertMirror(mirrorBST, val);
    }

    // 计算两棵树的前序遍历
    vector<int> bstPre, mirrorPre;
    preorder(bst, bstPre);
    preorder(mirrorBST, mirrorPre);

    // 判断输入是否匹配 BST 或镜像 BST
    if (input == bstPre || input == mirrorPre) {
        cout << "YES\n";
        vector<int> postSeq;
        postorder(input == bstPre ? bst : mirrorBST, postSeq);
        for (size_t i = 0; i < postSeq.size(); i++) {
            if (i > 0) cout << " ";
            cout << postSeq[i];
        }
        cout << endl;
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
