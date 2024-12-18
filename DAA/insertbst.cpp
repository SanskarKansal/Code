#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val=value;
        left=nullptr;
        right=nullptr;
    }
};
TreeNode* insertNode(TreeNode* root, int key) {
    if(root == nullptr) {
        return new TreeNode(key);
    }
    if(key < root->val) {
        root->left = insertNode(root->left, key);
    }
    else {
        root->right = insertNode(root->right, key);
    }
    return root;
}
void InOrder(TreeNode* root) {
    if(root != nullptr) {
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
    root = insertNode(root, 1);
    cout << "Tree after inserting node 1:" << endl;
    InOrder(root);
    cout << endl;
}