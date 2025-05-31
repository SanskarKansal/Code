#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Modular Exponentiation (a^b % mod)
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// GCD and LCM
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }

// Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        // Code for each test case
        int n,q;
        cin>>n>>q;
        vector<long long>a(n);
        vector<long long>pref(n+1);
        vector<long long>maxi(n+1);
        pref[0]=0;
        maxi[0]=1;
        for(int i=1;i<=n;i++){
            cin>>a[i-1];
            pref[i]=pref[i-1]+a[i-1];
            maxi[i]=max(maxi[i-1],a[i-1]);
        }
        for(int i=0;i<q;i++){
            long long val;
            cin>>val;
            int ind=upper_bound(maxi.begin(),maxi.end(),val)-maxi.begin()-1;
            if(ind>=0){
                cout<<pref[ind]<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}