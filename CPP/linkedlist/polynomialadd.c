#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct polynode{
    int coeff;
    int exp;
    struct polynode *link;
};
struct polynode* Insertpoly(struct polynode *poly,int c,int e);
void display(struct polynode *poly);
struct polynode* Addition(struct polynode *poly1,struct polynode *poly2);
int main()
{
    struct polynode *a=NULL;
    a=Insertpoly(a,3,14);
    a=Insertpoly(a,5,8);
    a=Insertpoly(a,6,0);
    display(a);
    printf("\n");
    struct polynode *b=NULL;
    b=Insertpoly(b,5,14);
    b=Insertpoly(b,8,9);
    b=Insertpoly(b,3,2);
    display(b);
    printf("\n");
    struct polynode *res=NULL;
    res=Addition(a,b);
    display(res);
    return 0;
}
struct polynode* Insertpoly(struct polynode *poly,int c,int e){
    struct polynode *nn;
    nn=malloc(sizeof(struct polynode));
    nn->coeff=c;
    nn->exp=e;
    nn->link=NULL;
    if(poly==NULL){
        poly=nn;
        return poly;
    }
    struct polynode *last=poly;
    while(last->link!=NULL){
        last=last->link;
    }
    last->link=nn;
    return poly;
}
void display(struct polynode *poly){
    if(poly==NULL){
        printf("Not Present");
        return;
    }
    while(poly!=NULL){
        printf(" %dx^%d ",poly->coeff,poly->exp);
        if(poly->link!=NULL){
            printf("+");
        }
        poly=poly->link;
    }
}
struct polynode* Addition(struct polynode *poly1,struct polynode *poly2){
    struct polynode* result;
    while(poly1!=NULL && poly2!=NULL){
        if(poly1->exp==poly2->exp){
            result=Insertpoly(result,poly1->coeff+poly2->coeff,poly1->exp);
            poly1=poly1->link;
            poly2=poly2->link;
        }
        else if(poly1->exp>poly2->exp){
            result=Insertpoly(result,poly1->coeff,poly1->exp);
            poly1=poly1->link;
        }
        else{
            result=Insertpoly(result,poly2->coeff,poly2->exp);
            poly2=poly2->link;
        }
    }
    while(poly1!=NULL){
        result=Insertpoly(result,poly1->coeff,poly1->exp);
        poly1=poly1->link;
    }
    while(poly2!=NULL){
        result=Insertpoly(result,poly2->coeff,poly2->exp);
        poly2=poly2->link;
    }
    return result;
}