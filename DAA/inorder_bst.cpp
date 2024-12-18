#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void inorder(Node* root,vector<int>& ans){
    if(root->left){
        inorder(root->left,ans);
    }
    ans.push_back(root->data);
    if(root->right){
        inorder(root->right,ans);
    }
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right=new Node(6);
    root->right->right=new Node(7);
    vector<int> ans;
    if(root!=nullptr){
        inorder(root,ans);
    }
    cout<<"inorder traversal: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}