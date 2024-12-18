#include<stdio.h>
int comp(int n){
    if(n==0){
        return n;
    }
    else{
        return n?n&=comp(n-1)+1:0;
    }
}
int main(){
   int d= comp(10);
   printf("%d",d);
    return 0;
}