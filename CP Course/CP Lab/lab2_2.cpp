#include<bits/stdc++.h>
using namespace std;
void prefix_max(int n, vector<int>& arr){
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int start;
        cin>>start;
        int end;
        cin>>end;
        if(start>=0 && end>=start && end<n){
            arr[start]+=100;
            arr[end+1]-=100;
        }
    }
    int prefix=arr[0];
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
        prefix=max(prefix,arr[i]);
    }
    cout<<prefix<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n+1,0);
        prefix_max(n,arr);
    }
}
/*
6
5
4
0 3
1 2
0 1
0 4
5
4
0 0
0 2
1 1
1 4
5
4
2 4
4 2
1 3
1 2
4
5
0 6
1 3
2 4
1 5
2 2
1
2
0 0
0 1
0
1
1 2
#400
#300
#300
#200
#100
#0
*/