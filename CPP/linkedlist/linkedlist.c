#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node*next;
};
struct node *add_to_list(struct node *list,int n){
    struct node*newnode;
     newnode=malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("error");
         exit(1);
    }
    newnode->value=n;
    newnode->next=list;
    return newnode;
    list=newnode;
    return list;
};
struct node *add_to_last(struct node *list,int n){
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    newnode->value=n;
    newnode->next=NULL;
    if(newnode==NULL){
        printf("error");
         exit(1);
    }
    struct node *cur;
    cur=list;
    if(cur==NULL){
        list = newnode;
        return list;
    }
    while(cur->next!=NULL){
        cur=cur->next;
    }
        cur->next=newnode;
        return list;

};
struct node *delete_node_n(struct node *list,int n){
    struct node *prev;
    struct node *cur;
     prev= NULL;
     cur =list;
    while(cur!=NULL && cur->value!=n){
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL){
        return list;
    }
    if(prev==NULL){
        list=list->next;
    }
    else{
        prev->next=cur->next;
        free(cur);
        return list;
}
};
struct node *delete_lastnode(struct node *list){
     struct node *prev;
    struct node *cur;
     prev= NULL;
     cur =list;
    while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
    }
    if(list->next==NULL){
        free(cur);
        free(list);
        return NULL;
    }
    else{
        prev->next=NULL;
    }
        free(cur);
        return list;
};
struct node *delete_firstnode(struct node *list){
    struct node *cur;
     cur =list;
    if(list->next==NULL){
        free(cur);
        free(list);
        return list;
    }
    else{
        cur=cur->next;
    }
        free(list);
        list=cur;
        return list;
};
struct node *delete_entirelist(struct node *list){
    struct node *cur;
     cur =list;
    while(cur!=NULL){
        cur=cur->next;
        free(list);
        list=cur;
    }
    return list;
};
void print(struct node*list){
    struct node*temp=list;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
}
int main(){
    struct node*list=NULL;
    list=add_to_list(list,5);
    list=add_to_list(list,8);
    list=add_to_list(list,6);
    list=add_to_list(list,12);
    list=delete_node_n(list,6);
    list=add_to_last(list,6);
    list=delete_lastnode(list);
    list=delete_firstnode(list);
    list=delete_entirelist(list);
    print(list);
}