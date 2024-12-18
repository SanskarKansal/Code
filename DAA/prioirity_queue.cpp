#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;
void heapify(vector<int>&a,int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && a[left]>a[largest]){
        largest=left;
    }
    if(right<n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
int heapsort(vector<int>& a,int n,int k){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    int i;
    for(i=n-1;i>=n-k;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
    return n-k;
}
int main(){
    int n;
    cout<<"enter the size : ";
    cin>>n;
    vector<int>a(n);
    int k;
    cout<<"kth number to be found:";
    cin>>k;
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    int ans=heapsort(a,n,k);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    cout<<endl;
    cout<<"answer is :"<<a[ans]<<endl;
}