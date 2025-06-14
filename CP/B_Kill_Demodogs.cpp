#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long mod=1e9+7;
int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;;
        long long ans=(((((n)*(n+1)%mod)*(4*n-1))%mod)*(337))%mod;
        cout<<ans<<endl;
    }
    return 0;
}