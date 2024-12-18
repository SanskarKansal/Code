#include<iostream>
using namespace std;
void merge(int arr[],int p,int q, int r,int m){
    int n1=q-p+1;
    int n2=r-q,l[100],b[100];
    for(int i=0;i<n1;i++){
      l[i]=arr[p+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[q+1+i];
    }
    l[n1]=m;
    b[n2]=m;
    int i=0,j=0;
    for(int k=p;k<=r;k++){
        if(l[i]<=b[j]){
            arr[k]=l[i];
            i=i+1;}
        else{
            arr[k]=b[j];
            j=j+1; }
        }
}
void mergesort(int arr[],int p, int r,int m){
    if(p<r){
      int q=(p+r)/2;
     mergesort(arr,p,q,m);
    mergesort(arr,q+1,r,m);
    merge(arr,p,q,r,m);
    }
}
int main()
{ int n;
 int arr[100];
 int m=0;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int a=n-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }
    mergesort(arr,0,a,m);
     cout<<"sorted array"<<endl;
    for(int i=0;i<=a;i++){
        cout<<arr[i]<<endl;
    }
    }