#include<stdio.h>
int main(){
    int n,i,j,temp,flag;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {flag=1;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
               flag=0; 
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    for(i=0;i<n;i++)
    {
         printf("%d ",a[i]);
    }
    return 0;
}