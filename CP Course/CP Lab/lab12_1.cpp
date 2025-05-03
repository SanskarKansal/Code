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

TreeNode* tree(vector<int>& preorder,vector<int>& inorder,int pstart,int pend,int istart,int iend){
    if(istart>iend){
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[pstart]);
    int index=istart;
    while(inorder[index]!=root->val){
        index++;
    }
    root->left=tree(preorder,inorder,pstart+1,index-istart+pstart,istart,index-1);
    root->right=tree(preorder,inorder,index-istart+pstart+1,pend,index+1,iend);
    return root;
}

void input(int n,vector<int> & preorder, vector<int> & inorder){
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
}

void print(TreeNode* root){
    if(!root){
        return ;
    }
    if(root->left){
        print(root->left);
    }
    if(root->right){
        print(root->right);
    }
    cout<<root->val<<" ";
}

void checktree(vector<int>& preorder,vector<int>& inorder,int pstart,int pend,int istart,int iend,TreeNode* node,int *check){
    if(istart>iend){
        return;
    }
    int value=preorder[pstart];
    if(value!=node->val){
        check=0;
    }
    int index=istart;
    while(inorder[index]!=node->val){
        index++;
    }
    checktree(preorder,inorder,pstart+1,index-istart+pstart,istart,index-1,node->left,check);
    checktree(preorder,inorder,index-istart+pstart+1,pend,index+1,iend,node->right,check);
    return ;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>preorder(n);
        vector<int>inorder(n);
        input(n,preorder,inorder);
        TreeNode* node= tree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        int check=1;
        checktree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,node,&check);
        cout<<check<<endl;
        print(node);
        cout<<endl;
    }
}

/*
8
1
1
1
7
1 2 4 5 3 6 7
4 2 5 1 6 3 7
2
1 2
2 1
5
1 2 3 4 7
3 2 1 7 4
5
1 2 3 4 5
3 4 5 2 1
4
1 2 3 4
4 3 2 1
2
1 2
1 2
3
1 2 3
2 1 3

#1
#4 5 2 6 7 3 1
#2 1 
#3 2 7 4 1 not complete tree
#5 4 3 2 1  half left the half right
#4 3 2 1
#2 1
#2 3 1
*/