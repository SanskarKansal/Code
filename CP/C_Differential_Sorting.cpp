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
        if(a[n-1]<a[n-2]){
            cout<<-1<<endl;
        }
        else if(a[n-1]>=0){
            cout<<n-2<<endl;
            for(int i=1;i<=n-2;i++){
                cout<<i<<" "<<n-1<<" "<<n<<endl;
            }
        }
        else{
            bool sorted=true;
            for(int i=1;i<n;i++){
                if(a[i-1]>a[i]){
                    sorted=false;
                    break;
                }
            }
            if(sorted){
                cout<<0<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}