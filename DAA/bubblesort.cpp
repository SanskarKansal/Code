#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
void bubble_sort(int arr[] ,int n ){
    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag){
            break;
        }
    }
}
int main(){
    int n;
    cout<<"enter the number of input: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand();
    }
    auto start = high_resolution_clock::now();
    bubble_sort(arr,n);
    auto stop = high_resolution_clock::now();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}