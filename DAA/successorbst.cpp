#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* findSuccessor(TreeNode* root, TreeNode* node) {
    if (node->right != nullptr) {
        TreeNode* current = node->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    
    TreeNode* successor = nullptr;
    while (root != nullptr) {
        if (node->val < root->val) {
            successor = root;
            root = root->left;
        } else if (node->val > root->val) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

void InOrder(TreeNode* root) {
    if (root != nullptr) {
        InOrder(root->left);
        cout << root->val << " ";
        InOrder(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    
    cout << "Original Tree:" << endl;
    InOrder(root);
    cout << endl;

    TreeNode* node = root->left;
    TreeNode* successor = findSuccessor(root, node);

    if (successor != nullptr) {
        cout << "The successor of node " << node->val << " is " << successor->val << endl;
    } else {
        cout << "No successor found for node " << node->val << endl;
    }

    return 0;
}
