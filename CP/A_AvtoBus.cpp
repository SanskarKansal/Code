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
        long long n;
        cin>>n;
        long long mini=-1,maxi=-1;
        long long val=n;
        int rem=val%6;
        if(rem==2){
            val-=8;
            if(val>=0){
                mini=2+val/6;
            }
        }
        else if(rem==4){
            val-=4;
            if(val>=0){
                mini=1+val/6;
            }
        }
        else if(rem==0){
            if(val>=0){
                mini=val/6;
            }
        }
        int rem2=n%4;
        if(rem2==2){
            n-=6;
            if(n>=0){
                maxi=1+n/4;
            }
        }
        else if(rem2==0){;
            if(n>=0){
                maxi=n/4;
            }
        }
        if(mini==-1 || maxi==-1){
            cout<<-1<<endl;
        }
        else{
            cout<<mini<<" "<<maxi<<endl;
        }
    }
    return 0;
}