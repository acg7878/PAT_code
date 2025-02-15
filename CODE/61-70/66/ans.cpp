#include <iostream>
#include <vector>

// AVL树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int x) : val(x), left(NULL), right(NULL), height(1) {}
};

// 获取节点高度
int getHeight(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// 更新节点高度
void updateHeight(TreeNode* node) {
    if (node != NULL) {
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }
}

// 获取节点平衡因子
int getBalanceFactor(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// 右旋
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// 左旋
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// 插入节点
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    // 左左情况
    if (balanceFactor > 1 && val < root->left->val) {
        return rightRotate(root);
    }
    // 右右情况
    if (balanceFactor < -1 && val > root->right->val) {
        return leftRotate(root);
    }
    // 左右情况
    if (balanceFactor > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // 右左情况
    if (balanceFactor < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> keys(N);
    for (int i = 0; i < N; i++) {
        std::cin >> keys[i];
    }

    TreeNode* root = NULL;
    for (int key : keys) {
        root = insert(root, key);
    }

    std::cout << root->val << std::endl;
    return 0;
}