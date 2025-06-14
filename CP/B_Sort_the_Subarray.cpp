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
        vector<long long>b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        long long l=-1;
        long long r=-1;
        long long diff=0;
        long long count=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(l==-1){
                    l=i;
                }
                else{
                    r=i;
                    break;
                }
            }
        }
        int i=l-1;
        while(i>=0){
            if(b[i]<=b[i+1]){
                i--;
            }
            else{
                break;
            }
        }
        l=i+1;
        if(r==-1){
            r=n-1;

        }
        i=r+1;
        while(i<n){
            if(b[i]>=b[i-1]){
                i++;
            }
            else{
                break;
            }
        }
        r=i-1;
        cout<<l+1<<" "<<r+1<<endl;
    }
    return 0;
}