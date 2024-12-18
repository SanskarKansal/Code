#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
};
typedef struct node NODE;
typedef struct node * NODEPTR;

NODEPTR maketree(int x) {
    NODEPTR p;
    p = malloc(sizeof(struct node));
    p->val = x;
    p->right = NULL;
    p->left = NULL;
    return p;
}

void preordertraversal(NODEPTR root) {
    if(root!=NULL) {
        printf("%d\t" ,root->val);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}
void inordertraversal(NODEPTR root) {
    if(root!=NULL) {
        inordertraversal(root->left);
        printf("%d\t" ,root->val);
        inordertraversal(root->right);
    }
}
void postordertraversal(NODEPTR root) {
    if(root!=NULL) {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d\t" ,root->val);
    }
}
// int counteach(NODEPTR root, c){
//     c++;
//     struct NODEPTR cur;
//     cur=root;
//     if(cur->left!=NULL){
//         count(NODEPTR cur,c)
//     }
// }
//     if(cur->right!=NULL){
//         count(NODEPTR cur,c)
//     }
//     return c;
// }
int main() {
    NODEPTR root = maketree(3);
    root->left = maketree(4);
    // root->right = maketree(3);
    (root->left)->left = maketree(1);
    // (root->left)->right = maketree(5);
    // (root->right)->left = maketree(5);
    // (root->right)->right = maketree(6);
    // ((root->left)->left)->left = maketree(7);

    printf("Pre Order is \n");
    preordertraversal(root);
    printf("\nin Order is \n");
    inordertraversal(root);
    printf("\nPost Order is \n");
    postordertraversal(root);
    // int c=0;
    // int k=counteach(root,c);
    // printf("%d",k);
}