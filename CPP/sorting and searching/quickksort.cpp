#include<stdio.h>
int partition(int A[],int p,int r)
{
    int pivot=A[r];
    int i=p-1;
    int temp;
    for(int j=p;j<=r-1;j++)
        if(A[j]<=pivot)
        {
            i++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}
void quicksort(int A[],int p ,int r)
{
    if(p<r)
    {
        int q= partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}
int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter the array for sorting : ");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("output array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}