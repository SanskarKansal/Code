#include<stdio.h>
int Binary(int a[],int f, int l,int x);
int main(){
    int n,i,x,j;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&x);
    for(i=1;i<n;i++)
    {
        int key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    printf("Sorted array is\n");
     for(i=0;i<n;i++)
    {
         printf("%d ",a[i]);
    }
    int c=Binary(a,0,n-1,x);
    if(c>=0)
    { printf("\nPosition of element in sorted array is:%d\n",c+1);}
    if(c==-1)
    {
        printf("\nNot Found");
    }
    
    return 0;
}
int Binary(int a[],int f,int l,int x){
    if(l<f)
    {
        return -1;
    }
    int mid=(f+l)/2;
    if(a[mid]==x)
    {
        return mid;
    }
    if(a[mid]<x)
    {
        return Binary(a,mid+1,l,x);
    }
    else
    {
        return Binary(a,f,mid-1,x);
    }
}