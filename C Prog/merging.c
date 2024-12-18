#include<stdio.h>
#include<limits.h>
void merge(int a[], int p, int r);
void mergesort(int a[], int p, int q, int r);
int main()
{
    int n,i,p,r;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    merge(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void merge(int a[],int p,int r){
    if(p<r)
    {
        int q=(p+r)/2;
        merge(a,p,q);
        merge(a,q+1,r);
        mergesort(a,p,q,r);
    }
}  
void mergesort(int a[],int p,int q,int r)
{
    int i;
    int n1=q-p+1;
    int n2=r-(q+1)+1;
    int l[n1],m[n2];
    for(i=0;i<n1;i++)
    {
       l[i]=a[p+i];
       
    }
    for(i=0;i<n2;i++)
    {
        m[i]=a[q+1+i];
        
    }
    l[n1]=INT_MAX;
    m[n2]=INT_MAX;
    int x=0,y=0;
    for(i=p;i<=r;i++)
    {
        if(l[x]<m[y])
        {
            a[i]=l[x];
            x++;
        }
        else
        {
            a[i]=m[y];
            y++;
        }
    }
    
}