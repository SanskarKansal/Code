#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
void merge(int arr[],int p,int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    int l[n1+1],b[n2+1];
    for(int i=0;i<n1;i++){
      l[i]=arr[p+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[q+1+i];
    }
    l[n1]=INT_MAX;
    b[n2]=INT_MAX;
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
void merge_sort(int arr[],int p, int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
int main(){
    int n;
    cout<<"enter the size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand();
    }
    auto start = high_resolution_clock::now();
    merge_sort(arr,0,n);
    auto stop = high_resolution_clock::now();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}