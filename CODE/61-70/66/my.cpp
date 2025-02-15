#include <algorithm>
#include <iostream>
#include <vector>
struct AVLTreeNode {
    int height;
    int val;
    AVLTreeNode* left;
    AVLTreeNode* right;
    AVLTreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(AVLTreeNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

void updateHeight(AVLTreeNode* node) {
    if (node != nullptr) {
        node->height =
            std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }
}

int getBalanceFactor(AVLTreeNode* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLTreeNode* rightRotate(AVLTreeNode* y) {
    AVLTreeNode* x = y->left;
    AVLTreeNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

AVLTreeNode* leftRotate(AVLTreeNode* x) {
    AVLTreeNode* y = x->right;
    AVLTreeNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

AVLTreeNode* leftRightRotate(AVLTreeNode* node) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

AVLTreeNode* rightLeftRotate(AVLTreeNode* node) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

AVLTreeNode* insert(AVLTreeNode* root, int val) {
    if (root == nullptr)
        return new AVLTreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    updateHeight(root);
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1 && val < root->left->val) {
        return rightRotate(root);
    }
    if (balanceFactor < -1 && val > root->right->val) {
        return leftRotate(root);
    }
    if (balanceFactor > 1 && val > root->left->val) {
        return leftRightRotate(root);
    }
    if (balanceFactor < -1 && val < root->right->val) {
        return rightLeftRotate(root);
    }
    return root;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> elems(n);
    for (int i = 0; i < n; i++) {
        std::cin >> elems[i];
    }
    AVLTreeNode* root = nullptr;
    for (int elem : elems) {
        root = insert(root, elem);
    }
    std::cout << root->val << std::endl;
    return 0;
}