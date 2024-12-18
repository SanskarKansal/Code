#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *next;
};

void print(struct node *cllist) {
    struct node *cur = cllist;
    do {
        printf("%d\t", cur->val);
        cur = cur->next;
    }while(cur!=cllist);
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

struct node *delete(struct node *cllist, struct node *ptr) {
    struct node *temp;
    if(cllist==NULL) {
        printf("Attempt to delete empty list");
        exit(1);
    } else {
        temp = ptr->next;
        if(temp==ptr) {
            cllist = NULL;
        } else {
            ptr->next = temp->next;
        }
        free(temp);
        return cllist;
    }
}
int main() {
    struct node *head = NULL;
    for(int i=1; i<5; i++) {
        head = insert(head,head,i);
    }
    head = delete(head,head);
    print(head);
}