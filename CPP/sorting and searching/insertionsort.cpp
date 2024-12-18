#include<stdio.h>
void insertionsort(int n, int a[]){
int i,j,key;
for(i=1;i<n;i++){
    key=a[i];
    j=i-1;
while(j>=0 && a[j]>key){
    a[j+1]=a[j];
    j=j-1;
    a[j+1]=key;}
}  
for(int i=0;i<n;i++){
    printf("%d",a[i]);
}
}
int main(){
    int n;
    printf("enter the value of n: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertionsort(n,a);
    return 0;
}
