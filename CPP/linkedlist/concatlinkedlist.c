#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
struct node *Insertatlast(struct node *list,int n);
void display(struct node *list);
struct node *Concat(struct node *list1,struct node *list2);
int main()
{
    struct node *list1=NULL;
    struct node *list2=NULL;
    struct node *result=NULL;
    int i,x;
    printf("Enter the 5 Numbers of first list:");
    for(i=0;i<5;i++){
        scanf("%d",&x);
        list1=Insertatlast(list1,x);
    }
    printf("Enter the 5 Numbers of second list:");
    for(i=0;i<5;i++){
        scanf("%d",&x);
        list2=Insertatlast(list2,x);
    }
    result=Concat(list1,list2);
    display(result);
    return 0;
}

void display(struct node *list){
    while(list!=NULL){
        printf("%3d",list->val);
        list=list->next;
    }
    return;
}

struct node* Insertatlast(struct node *list,int n){
    struct node* nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->val=n;
    nn->next=NULL;
    if(list==NULL){
        return nn;
    }
    struct node* temp;
    temp=list;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nn;
    return list;
}

struct node *Concat(struct node *list1,struct node *list2){
    struct node *temp=list1;
    if(list1==NULL){
        return list2;
    }
    while((temp->next)!=NULL){
        temp=temp->next;
    }
    temp->next=list2;
    return list1;
}