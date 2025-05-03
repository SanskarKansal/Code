#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode*right;
    TreeNode(int value){
        val=value;
        left=NULL;
        right=NULL;
    }
};

void printpath(vector<vector<int>>& ans){
    int len=ans.size();
    for(int i=0;i<len;i++){
        int pathsize=ans[i].size();
        for(int j=0;j<pathsize;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

TreeNode* input(TreeNode* node){
    int value;
    cin>>value;
    node=new TreeNode(value);
    int check;
    cin>>check;
    if(check){
        node->left=input(node->left);
    }
    cin>>check;
    if(check){
        node->right=input(node->right);
    }
    return node;
}

TreeNode* solve(){
    int check;
    cin>>check;
    TreeNode* root;
    if(check==1){
        int val;
        cin>>val;
        root=new TreeNode(val);
        cin>>check;
        if(check){
            root->left=input(root->left);
        }
        cin>>check;
        if(check){
            root->right=input(root->right);
        }
    }
    return root;
}

void print(TreeNode* root){
    if(!root){
        return ;
    }
    cout<<root->val<<" ";
    if(root->left){
        print(root->left);
    }
    if(root->right){
        print(root->right);
    }
}

void findsum(TreeNode* node,vector<int>& path, vector<vector<int>>& ans ,int sum,int k){
    if(!node){
        return;
    }
    path.push_back(node->val);
    if((sum+node->val)==k){
        ans.push_back(path);
    }
    findsum(node->left,path,ans,sum+node->val,k);
    findsum(node->right,path,ans,sum+node->val,k);
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        TreeNode* root=solve();
        vector<int>path;
        vector<vector<int>>ans;
        findsum(root,path,ans,0, k);
        printpath(ans);
    }
}
/*
6
8
1 5 1 3 0 1 7 0 0
18
1 10 1 5 1 3 0 0 1 2 0 0 1 8 0 0
5
1 5 0 0
7
1 3 1 2 0 0 1 4 0 0
3
1 1 1 1 1 1 0 0 0 0
28
1 10 1 5 1 3 0 0 0 1 15 1 8 0 0 1 5 0 0

#
5 3
10 5 3
5
3 4
1 1 1
10 15 8 5

*/