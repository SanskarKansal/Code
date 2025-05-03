#include<bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int>v,int n, int k){
    priority_queue<int,vector<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(v[i]);
        if(pq.size()>k) pq.pop();

    }
    return pq.top();
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        cout << kthSmallest(v,n,k) << endl;

}
}

/*
7
5 3
2 5 8 1 10
6 4
-1 4 7 2 0 5
7 1
-1 4 7 2 0 5 9
5 5
-1 4 7 2 5
5 2
1 2 3 4 5
6 3
8 6 4 2 1 -5
1 1
1
#
5
4
-1
7
2
2
1
*/