#include<bits/stdc++.h>
using namespace std;

void stockspan(int n, vector<int> &arr, vector<int> & ans){
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=i+1;
        }
        else{
            ans[i]=i-st.top();
        }
        st.push(i);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==0){
            cout<<-1<<endl;
        }
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>ans(n);
        stockspan(n,arr,ans);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}

/*
10
4
20 20 40 50
4
50 40 30 20
4
50 20 40 30
6
50 20 30 30 40 10
6
10 60 30 40 10 30
4
30 30 30 30
1
10
2
10 20
2
20 10
0

#1 2 3 4
#1 2 3 4
#1 1 2 1
#1 1 2 3 4 1
#1 2 1 2 1 2
#1 1 2 3 4
#1
#1 2
#1 1
#-1
*/