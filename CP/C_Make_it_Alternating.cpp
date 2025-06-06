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
long long mod=998244353;
int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        // Code for each test case
        string s;
        cin>>s;
        int n=s.length();
        long long extra=0,opr=0,fac=1,choice=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                extra++;
            }
            else{
                opr+=extra;
                extra++;
                choice=(choice%mod * extra%mod)%mod;
                extra=0;
            }
        }
        if(extra>0){
            opr+=extra;
            extra++;
            choice=(choice%mod * extra%mod)%mod;
            extra=0;
        }
        for(int i=1;i<=opr;i++){
            fac=(fac%mod * i%mod)%mod;
        }
        choice=(choice%mod*fac%mod)%mod;
        cout<<opr<<" "<<choice<<endl;
    }
    return 0;
}