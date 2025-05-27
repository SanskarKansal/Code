#include <bits/stdc++.h>
using namespace std;

void msb(int x, map<int,int>&mp) {
    int b = 0;
    while (x > 0) {
        b++;
        if(x==1){
            mp[b]++;
        }
        x >>= 1;
    }
}

int main() {
   int t;
   cin>>t;
   while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int>mp;
        for(int i=0;i<n;i++) {
            cin >> a[i];
            msb(a[i] , mp);
        }
        long long ans = 0;
        for(auto i: mp){
            ans+=(1LL*(i.second)*(i.second-1))/2;
        }
        cout << ans<<endl;
   }
}
