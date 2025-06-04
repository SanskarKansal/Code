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
        int n,k;
        cin>>n>>k;
        vector<int>bits(31,0);
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            int j=0;
            while(val>0){
                if(val%2){
                    bits[30-j]++;
                }
                val/=2;
                j++;
            }
        }
        int ans=0;
        int i=0;
        while(k>0 && i<=30){
            if(n-bits[i]>k){
                i++;
            }
            else{
                k-=(n-bits[i]);
                ans+=pow(2,30-i);
                i++;
            }
        }
        while(i<=30){
            if(bits[i]==n){
                ans+=pow(2,30-i);
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}