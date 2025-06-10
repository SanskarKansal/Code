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
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int i=0;
        long long ans=1;
        vector<long long>val;
        val.push_back(a[0]);
        while(i<n-1){
            int k=i+1;
            while(k<n && a[k]>=a[k-1]){
                k++;
            }
            int j=i+1;
            while(j<n && a[j]<=a[j-1]){
                j++;
            }
            int ind=max(k-1,j-1);
            ans++;
            val.push_back(a[ind]);
            i=ind;
        }
        cout<<ans<<endl;
        for(int i=0;i<val.size();i++){
            cout<<val[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}