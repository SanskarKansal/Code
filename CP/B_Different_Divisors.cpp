#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool isprime(int n) {
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin>>d;
        int val=1;
        int ans=1;
        val+=d;
        while(!isprime(val)){
            val++;
        }
        ans*=val;
        val+=d;
        while(!isprime(val)){
            val++;
        }
        ans*=val;
        cout<<ans<<endl;
    }
    return 0;
}