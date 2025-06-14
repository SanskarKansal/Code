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
        string s;
        cin>>s;
        long long ans=0;
        long long i=0;
        long long val=0;
        long long n=s.length();
        while (i < n) {
            if (s[i] == '1') {
                long long j = i;
                while (j < n && s[j] == '1') j++;
                val = max(val, j - i);
                i = j;
            } else {
                i++;
            }
        }
        if(s[0]=='1' && s[n-1]=='1' && val<n){
            long long start = 0, end = 0;
            while (start < n && s[start] == '1'){
                start++;
            }
            while (end < n && s[n - 1 - end] == '1'){
                end++;
            }
            val = max(val, start + end);;
        }
        ans=val;
        for(int i=1;i<val;i++){
            ans=max(ans,(i+1)*(val-i));
        }
        if(val==n){
            ans=n*n;
        }
        cout<<ans<<endl;
    }
    return 0;
}