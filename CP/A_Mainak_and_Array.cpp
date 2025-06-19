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
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=a[n-1]-a[0];
        int mini=a[0];
        for(int i=0;i<n-1;i++){
            mini=min(mini,a[i]);
        }
        ans=max(ans,a[n-1]-mini);
        int maxi=a[n-1];
        for(int i=1;i<n;i++){
            maxi=max(maxi,a[i]);
        }
        ans=max(ans,maxi-a[0]);
        for(int i=1;i<n;i++){
            ans=max(ans,a[i-1]-a[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}