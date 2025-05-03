/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        void calc(TreeNode* root,vector<int>&a){
            if(root==nullptr){
                return;
            }
            calc(root->left,a);
            a.push_back(root->val);
            calc(root->right,a);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int>a;
            calc(root,a);
            return a;
        }
    };