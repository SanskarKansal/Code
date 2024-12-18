#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node*next;
};
struct node * list=NULL;
void createEmptylinkedlist(struct node **head){
    *head=malloc(sizeof(struct node));
    (*head)->next=NULL;
}
void insert(struct node *ptr,int n){
    struct node* n_n;
    n_n=malloc(sizeof(struct node));
    n_n->value=n;
    n_n->next=ptr->next;
    ptr->next=n_n;

}
void printlinkedlist(struct node*list){
    struct node*curr=list->next;
    if(curr==NULL){
        printf("empty list");
        return;
    }
    while(curr!=NULL){
        printf("%d\n", curr->value);
        curr=curr->next;
    }
}
void delete(struct node * ptr){
    struct node * temp;
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
}
void insertionatlast(struct node *ptr,int n){
     struct node* n_n;
    n_n=malloc(sizeof(struct node));
    n_n->value=n;
    n_n->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=n_n;
}
void deleteatlast(struct node * ptr){
    struct node * curr,*prev;
    prev=NULL;
    curr=ptr;
    while(curr->next!=NULL){
       prev=curr;
        curr=curr->next;
    }
    free(curr);
    prev->next=NULL;
}
int main(){
    struct node*head=NULL;
    createEmptylinkedlist(&head);
    insert(head,7);
    insert(head,0);
    insert(head,1);
    insert(head,8);
    insertionatlast(head,7);
    deleteatlast(head);
    delete(head);
    printlinkedlist(head);
}