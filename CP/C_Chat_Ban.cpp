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
        long long k,x;
        cin>>k>>x;
        long long ans=1;
        long long left=1,right=2*k-1;
        while(left<=right){
            long long mid=(left+right)/2;
            long long val;
            if(mid<=k){
                val=mid*(mid+1)/2;
            }
            else{
                long long temp=2*k-1-mid;
                val=k*(k+1)/2+k*(k-1)/2-temp*(temp+1)/2;
            }
            if(val==x){
                ans=mid;
                break;
            }
            if(val<x){
                ans=mid+1;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        cout<<min(ans,2*k-1)<<endl;
    }
    return 0;
}