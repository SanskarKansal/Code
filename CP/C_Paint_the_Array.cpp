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
        long long g1=0;
        long long g2=0;
        for(int i=0;i<n;i++){
            if(i%2){
                g2=gcd(g2,a[i]);
            }
            else{
                g1=gcd(g1,a[i]);
            }
        }
        bool check=true;
        for(int i=1;i<n;i+=2){
            if(a[i]%g1==0){
                check=false;
                break;
            }
        }
        if(check){
            cout<<g1<<endl;
        }
        else{
            check=true;
            for(int i=0;i<n;i+=2){
                if(a[i]%g2==0){
                    check=false;
                    break;
                }
            }
            if(check){
                cout<<g2<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}