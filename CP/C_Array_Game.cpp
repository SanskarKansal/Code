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
        long long n,k;
        cin>>n>>k;
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(k==1){
            sort(a.begin(),a.end());
            long long mini=a[0];
            for(int i=1;i<n;i++){
                mini=min(mini,a[i]-a[i-1]);
            }
            cout<<mini<<endl;
        }
        else if(k==2){
            sort(a.begin(),a.end());
            long long mini = abs(a[1]-a[0]);
            for (int i = 0; i < n; i++) {
                mini=min(mini,a[i]);
                for (int j = i + 1; j < n; j++) {
                    long long val=abs(a[j]-a[i]);
                    mini=min(mini,val);
                    auto it = lower_bound(a.begin(), a.end(), val);
                    if (it != a.end()) mini = min(mini, abs(*it - val));
                    if (it != a.begin()) mini = min(mini, abs(*(it - 1) - val));

                }
            }
            cout<<mini<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}