#include<stdio.h>
int main()
{
    int n,i,m;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to find:");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        if(a[i]==m)
        {
            printf("position of %d is %d",m,i+1);
        }
    }
    return 0;
}