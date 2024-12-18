#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node *next;
};
struct Node* Insertatfirst(struct Node *list,int n);
struct Node* ReverseLL(struct Node *list); 
void print(struct Node *list);
int main()
{
    struct Node *list=NULL;
    list=Insertatfirst(list,2);
    list=Insertatfirst(list,3);
    list=Insertatfirst(list,4);
    list=Insertatfirst(list,5);
    list=Insertatfirst(list,6);
    list=Insertatfirst(list,7);
    list=Insertatfirst(list,8);
    list=Insertatfirst(list,9);
    print(list);
    list=ReverseLL(list);
    print(list);
    return 0;
}
struct Node* Insertatfirst(struct Node *list,int n){
    struct Node *nn;
    nn=malloc(sizeof(struct Node));
    if(nn==NULL){
        printf("Error");
        exit(1);
    }
    nn->val=n;
    nn->next=list;
    list=nn;
    return list;
}
struct Node* ReverseLL(struct Node *list){
    struct Node *prev=NULL;
    struct Node *cur=list;
    struct Node *temp=NULL;
    while(cur!=NULL){
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    list=prev;
    return list;
}
void print(struct Node *list){
    while(list!=NULL){
        printf("%3d",list->val);
        list=list->next;
    }
    printf("\n");
    return;
}