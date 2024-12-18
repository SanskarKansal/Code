#include<iostream>
#include<vector>
using namespace std;
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
void heapsort(vector<int>& a,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main(){
    int n;
    cout<<"enter size: ";
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
    auto start=high_resolution_clock::now();
    heapsort(a,n);
    auto stop=high_resolution_clock::now();
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}













