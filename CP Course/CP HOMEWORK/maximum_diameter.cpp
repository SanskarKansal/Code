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
        int widthOfBinaryTree(TreeNode* root) {
            queue<pair<TreeNode*,long long>>q;
            q.push({root,1LL});
            long long ans=0;
            while(!q.empty()){
                int n=q.size();
                long long v=q.front().second;
                long long left,right;
                for(int i=0;i<n;i++){
                    TreeNode* a=q.front().first;
                    long long val=q.front().second-v;
                    q.pop();
                    if(i==0){
                        left=val;
                    }
                    if(i==n-1){
                        right=val;
                    }
                    if(a->left){
                        q.push({a->left,(val*2)});
                    }
                    if(a->right){
                        q.push({a->right,(val*2+1)});
                    }
                }
                ans=max(ans,right-left+1);
            }
            return ans;
        }
    };