#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;
int partition(vector<int>&a,int p,int r){
    int pivot=a[r];
    int i=p-1;
    int temp;
    for(int j=p;j<=r-1;j++)
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    swap(a[i+1],a[r]);
    return i+1;
}
void quicksort(vector<int>&a,int p,int r){
    if(p<r){
        int  q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
    auto start=high_resolution_clock::now();
    quicksort(a,0,n-1);
    auto stop=high_resolution_clock::now();
    cout<<"final ans: "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}