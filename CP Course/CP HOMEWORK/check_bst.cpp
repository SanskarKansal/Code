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
        bool isValidBST(TreeNode* root) {
            stack<TreeNode*>s;
            TreeNode* cur=root;
            int check=INT_MIN;
            int c=0;
            while(cur!=nullptr ||!s.empty()){
                while(cur!=nullptr){
                    s.push(cur);
                    cur=cur->left;
                }
                cur=s.top();
                s.pop();
                if(check>=cur->val){
                    if(c!=0){
                        return false;
                    }
                }
                c=1;
                check=cur->val;
                cur=cur->right;
            }
            return true;
        }
    };