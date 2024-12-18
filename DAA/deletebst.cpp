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

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;
    
    if (key < root->val) 
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp && temp->left != nullptr)
            temp = temp->left;
        
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
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
    
    root = deleteNode(root, 3);
    
    cout << "Tree after deleting node 3:" << endl;
    InOrder(root);
    cout << endl;
    
    return 0;
}
