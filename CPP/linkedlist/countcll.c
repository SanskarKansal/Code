#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *next;
};

void printtotalnode(struct node *cllist) {
    struct node *cur = cllist;
    int count = 0;
    do {
        count++;
        printf("%d\t", cur->val);
        cur = cur->next;
    }while(cur!=cllist);
    printf("\n%d" ,count);
}
struct node *insert(struct node *cllist, struct node *ptr, int n) {
    struct node *nn;
    nn = malloc(sizeof(struct node));
    nn->val = n;
    if(cllist==NULL) {
        nn->next = nn;
        cllist = nn;
    } else {
        nn->next = ptr->next;
        ptr->next = nn;
    }
    return cllist;
}
int main() {
    struct node *head = NULL;
    for(int i=1; i<5; i++) {
        head = insert(head,head,i);
    }
    head = insert(head,head,5);
    printtotalnode(head);
}