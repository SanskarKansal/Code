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
void deleteval(TreeNode* parent, TreeNode* node) {
    while(node->right != nullptr) {
        parent = node;
        node = node->right;
    }
    if(node == parent->left) {
        parent->left = node->left;
    }
    else {
        parent->right = node->left;
    }
}
TreeNode* maximum(TreeNode* root) {
    while(root->right != nullptr) {
        root = root->right;
    }
    return root;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* x = root;
    TreeNode* parent = nullptr;
    while(x != nullptr && x->val != key) {
        parent = x;
        if(x->val > key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    if(x == nullptr){
        return root;
    }
    if(x->left == nullptr || x->right == nullptr){
        TreeNode* Child = (x->left != nullptr) ? x->left : x->right;
        if(parent == nullptr){
            return Child;
        }
        if(x == parent->left) {
            parent->left = Child;
        }
        else {
            parent->right = Child;
        }
    } 
    else {
        TreeNode* Node = maximum(x->left);
        x->val = Node->val;
        deleteval(x, x->left);
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
    root =deleteNode(root, 3);
    cout << "Tree after deleting node 3:" << endl;
    InOrder(root);
    cout << endl;
}
