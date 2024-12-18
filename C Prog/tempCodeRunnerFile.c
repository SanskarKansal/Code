#include<stdio.h>
int main(){
    int n;
    printf("enter the vlaue of n: ");
    scanf("%d",&n);
    int a[n];
    int b[n];
    int i,l,k=2;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]==-1){
            b[i]=1;
            l=i;
            break;
        }
    }
    for(i=0;i<l;i++){
        b[i]=k;
        k++;
    }
    for(i=l+1;i<n;i++){
        b[i]=i+1;
    }
    for(i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    return 0;
}