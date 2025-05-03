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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>>ans;
            if(root==nullptr){
                return ans;
            }
            queue<TreeNode*>q;
            q.push(root);
            int count=0;
            while(!q.empty()){
                int a=q.size();
                vector<int>temp;
                for(int i=0;i<a;i++){
                    TreeNode* var=q.front();
                    temp.push_back(var->val);
                    q.pop();
                    if(var->left!=nullptr){
                        q.push(var->left);
                    }
                    if(var->right!=nullptr){
                        q.push(var->right);
                    }
                }
                if(count%2==1){
                    reverse(temp.begin(),temp.end());
                }
                ans.push_back(temp);
                count++;
            }
            return ans;
        }
    };