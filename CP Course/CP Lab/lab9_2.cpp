#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr ,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            count++;
        }
    }
    if(count==0){
        int val=INT_MAX;
        for(int i=0;i<n;i++){
            val=min(val,arr[i]);
        }
        return val;
    }
    else{
        int val=INT_MIN;
        int ans=1;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                ans=ans*arr[i];
            }
            if(arr[i]<0){
                val=max(val,arr[i]);
            }
        }
        if(count%2){
            return ans;
        }
        return ans/val;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=solve(arr,n);
        cout<<ans<<endl;
    }
    return 0;
}

/*
11
4
1 2 3 4
5
0 2 3 5 4
4
-2 1 2 3
5
-2 0 4 2 5
6
-1 0 4 -3 1 4
5
-2 -3 0 5 3
6
-2 -3 -1 -4 -5 -2
5
-1 -2 -4 -5 -3
1
2
1
0
1
-3
# 1
# 0
# -12
# -80
# -48
# -45
# -240
# -120
# 2
# 0
# -3
*/