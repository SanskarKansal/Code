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
        int mini=0;
        vector<int>mini1(n);
        mini1[0]=0;
        for(int i=0;i<n;i++){
            if(a[i]<a[mini]){
                mini=i;
            }
            mini1[i]=mini;
        }
        vector<int>mini2(n);
        mini2[0]=n-1;
        mini=n-1;
        for(int i=n-1;i>=0;i--){
            if(a[i]<a[mini]){
                mini=i;
            }
            mini2[i]=mini;
        }
        int i=0;
        for(i=0;i<n;i++){
            if(a[i]>a[mini1[i]] && a[i]>a[mini2[i]]){
                cout<<"YES"<<endl;
                cout<<mini1[i]+1<<" "<<i+1<<" "<<mini2[i]+1<<endl;
                break;
            }
        }
        if(i==n){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}