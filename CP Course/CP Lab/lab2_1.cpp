#include<bits/stdc++.h>
using namespace std;
void kadane(int n,vector<int>& arr){
    int max_sum=INT_MIN;
    int sum=0;
    if(n==0){
        cout<<0<<endl;
        return ;
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
        max_sum=max(max_sum,sum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<max_sum<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        kadane(n,arr);
    }
}
 /*
 7
 5
 1 2 3 4 5 
 6
 1 4 -3 4 -2 6 
 5
 0 0 0 0 0  
 6
 1 -1 1 -1 1 -1 
 5
 4 -2 3 -1 5  
 6
 -2 -3 -4 -1 -5 -8 
 10
 1 -2 6 -2 5 -6 2 -1 6 -4 
 
 #15
 #10
 #0
 #1
 #9
 #-1 
 #10
 */