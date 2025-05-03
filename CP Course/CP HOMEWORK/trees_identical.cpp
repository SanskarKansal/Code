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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (p == nullptr && q == nullptr) {
                return true;
            }
            if (p == nullptr || q == nullptr) {
                return false;
            }
            queue<TreeNode*> a, b;
            a.push(p);
            b.push(q);
            while (!a.empty() && !b.empty()) {
                TreeNode* c = a.front();
                a.pop();
                TreeNode* d = b.front();
                b.pop();
                if (c->val != d->val) {
                    return false;
                }
                if ((c->left == nullptr) != (d->left == nullptr)) {
                    return false;
                }
                if ((c->right == nullptr) != (d->right == nullptr)) {
                    return false;
                }
                if (c->left != nullptr) {
                    a.push(c->left);
                    b.push(d->left);
                }
                if (c->right != nullptr) {
                    a.push(c->right);
                    b.push(d->right);
                }
            }
            return true;
        }
    };
    