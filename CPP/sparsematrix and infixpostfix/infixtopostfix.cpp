#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct Stack{
    int top;
    char items[100];
};
bool empty(struct Stack *ps);
void push(struct Stack *ps,char x);
void pop(struct Stack *ps,char *x);
bool precedence(struct Stack *ps,char Symbol);
int compare(char op);
int main()
{
    char a[100];
    char b[100];
    int i=0;
    int j=0;
    struct Stack S;
    puts("Enter the infix expression");
    fgets(a,100,stdin);
    S.top=-1;
    char symbol;
    char topsym;
    while(a[i+1]!='\0'){
        symbol=a[i];
        if(a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/'){
            b[j++]=a[i];  
        }
        else{
            while(!empty(&S) && precedence(&S,symbol)){
                pop(&S,&topsym);
                b[j++]=topsym;
        
            }
            push(&S,symbol);
        }
        i++;
    }
    while (!empty(&S)) {
        pop(&S, &topsym);
        b[j++] = topsym;
    }
    for(i=0;i<j;i++){
        printf("%2c",b[i]);
    }
    return 0;
}
bool empty(struct Stack *ps){
    if(ps->top==-1){
        return true;
    }
    else{
        return false;
    }
}
void push(struct Stack *ps,char x){
    if(ps->top==98){
        printf("Overflow");
        exit(1);
    }
    (ps->items[++(ps->top)])=x;
    return;
}
void pop(struct Stack *ps,char *x){
    if(empty(ps)){
        printf("Underflow");
        exit(1);
    }
    *x=(ps->items[(ps->top)--]);
    return;
}
bool precedence(struct Stack *ps,char symbol){
    if(empty(ps)){
        printf("Underflow");
        exit(1);
    } 
    int prec1=compare(ps->items[ps->top]);
    int prec2=compare(symbol);
    if(prec1>=prec2){
        return true;
    } 
    else
        return false; 
}
int compare(char op){
    switch(op){
        case '+':case '-':{
            return 1;
        }
        case '*':case '/':{
            return 2;
        } 
    }
}