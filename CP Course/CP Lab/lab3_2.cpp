#include<bits/stdc++.h>
using namespace std;

void heapsort(int n,int k, vector<int> &arr, vector<int> & ans){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<min(n,k);i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<min(n,k);i++){
        pq.push(arr[i]);
        ans[i-k]=pq.top();
        pq.pop();
    }
    int i=max(n-k,0);
    while(!pq.empty()){
        ans[i]=pq.top();
        pq.pop();
        i++;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>ans(n);
        heapsort(n,k,arr,ans);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}

/*
8
1
1
0
5
5 4 3 2 1
1
6
10 9 8 7 4 5
2
6
6 5 4 3 2 1
3
6
1 3 2 6 5 4
2
4
1 2 3 4
4
4
1 2 3 4
5
6
6 5 4 3 2 1
10
#
1
4 5 3 2 1
8 9 10 4 5 7
3 4 5 6 1 2
1 2 3 4 5 6
1 2 3 4
1 2 3 4
1 2 3 4 5 6
*/