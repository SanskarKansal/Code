#include<bits/stdc++.h>
using namespace std;

void input(int n,vector<int>& arr){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void findIndices(int n, vector<int>& arr, int x) {
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        int complement = x - arr[i];
        if(mp.count(complement)) {
            cout << mp[complement] << " " << i << "\n";
            return;
        }
        mp[arr[i]] = i;
    }
    cout << "-1 -1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<int> arr(n);
        input(n, arr);
        cin >> x;
        findIndices(n, arr, x);
    }
    return 0;
}

/*
9
1
5
10
2
3 7
10
2
1 2
5
6
1 2 3 4 5 6
7
4
2 2 2 2
4
5
-3 1 2 0 4
1
5
1000000000 2000000000 3000000000 4000000000 5000000000
7000000000
6
1 3 2 2 3 1
4
3
1 2 4
4

#
-1 -1
0 1
-1 -1
0 5
0 1
0 4
1 3
0 1
0 2
*/