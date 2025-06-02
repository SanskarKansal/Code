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

long long intPow(long long base, int exp) {
    long long res = 1;
    while (exp--) {
        if (__builtin_mul_overflow(res, base, &res)){
            return LLONG_MAX;
        }
    }
    return res;
}

long long INF=pow(10,6);
int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        // Code for each test caseinz
        int n;
        cin>>n;
        bool check=false;
        for(int j=3;j<=70;j++){
            long long left=2;
            long long right=INF;
            while(left<=right){
                long long mid=(left+right)/2;
                long long num = intPow(mid, j);
                if (num == LLONG_MAX) {
                    right = mid - 1;
                    continue;
                }
                long long val = (num - 1) / (mid - 1);
                if(val==n){
                    check=true;
                    break;
                }
                else if(val>n){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            if(check){
                break;
            }
        }
            if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}