#include<iostream>
using namespace std;
void merge(int arr[],int p,int q, int r)
{
    int n1=q-p+1;
    int n2=r-q,l[n1+1],b[n2+1];
    for(int i=0;i<n1;i++){
      l[i]=arr[p+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[q+1+i];
    }
    

    int i=0,j=0;
    for(int k=p;k<=r;k++){
        if(i==n1||j==n2){
            if(i==n1){
            arr[k]=b[j];
            j=j+1;}
            else{
            arr[k]=l[i];
            i=i+1; }
        }
        else if(l[i]<=b[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=b[j];
           j++;
        }
    }
}
void mergesort(int arr[],int p, int r)
{
    if(p<r){
      int q=(p+r)/2;
     mergesort(arr,p,q);
    mergesort(arr,q+1,r);
    merge(arr,p,q,r);}
}
int main()
{ 
    int n;
    int m=0;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    int a=n-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   
    mergesort(arr,0,a);
     cout<<"sorted array"<<endl;
    for(int i=0;i<=a;i++){
        cout<<arr[i]<<endl;
    }
}