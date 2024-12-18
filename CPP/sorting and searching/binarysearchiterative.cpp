#include<stdio.h>
int main()
{
    int n,i,m,j,temp,x,y,mid;
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
        for(j=i+1;j<n-1;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    x=0;
    y=n-1;
    while(y>x)
    {
        mid=(x+y)/2;
        if(a[mid]==m)
        {
            printf("\nposition of %d element in sorted array is %d",m,mid+1);
            break;
        }
        else if(a[mid]<m)
        {
            x=mid+1;
        }
        else
        {
           y=mid-1;
        }
    }
    return 0;
}