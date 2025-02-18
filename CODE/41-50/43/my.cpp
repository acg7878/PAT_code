#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){};
};

TreeNode* insert(TreeNode* root,int val) {
    if(root == nullptr) return new TreeNode(val);
    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

TreeNode* mirror_insert(TreeNode* root,int val) {
    if(root == nullptr) return new TreeNode(val);
    if(val < root->val) root->right = mirror_insert(root->right, val);
    else root->left = mirror_insert(root->left, val);
    return root;
}

void preOrder(TreeNode* root,std::vector<int>& pre_vec) {
    if (!root) return;
    pre_vec.push_back(root->val);
    preOrder(root->left,pre_vec);
    preOrder(root->right,pre_vec);
}

void postOrder(TreeNode* root,std::vector<int>& post_vec) {
    if(!root) return;
    postOrder(root->left, post_vec);
    postOrder(root->right,post_vec);
    post_vec.push_back(root->val);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nodes(n);
    for(int i=0;i<n;i++){
        std::cin >> nodes[i];
    }
    TreeNode* root = nullptr;
    TreeNode* mirror_root = nullptr;
    for(int node : nodes) {
        root = insert(root, node);
        mirror_root = mirror_insert(mirror_root, node);
    }
    std::vector<int> pre_vec,mirror_pre_vec;
    preOrder(root,pre_vec);
    preOrder(mirror_root, mirror_pre_vec);

    if(nodes == pre_vec || nodes == mirror_pre_vec) {
        std::cout << "YES" << std::endl;
        std::vector<int> post_vec;
        postOrder(nodes == pre_vec?root:mirror_root, post_vec);
        for(size_t i = 0;i<post_vec.size();i++) {
            if(i > 0) std::cout << " ";
            std::cout << post_vec[i];
        }
        std::cout << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }


}