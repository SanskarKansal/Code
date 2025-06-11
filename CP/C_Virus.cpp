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
        int n,m;
        cin>>n>>m;
        vector<long long>a(m);
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<long long>gap;
        for(int i=1;i<m;i++){
            gap.push_back(a[i]-a[i-1]-1);
        }
        gap.push_back(n-a[m-1]+a[0]-1);
        sort(gap.rbegin(),gap.rend());
        int days=0;
        int saved=0;
        for(auto i:gap){
            int cur=i-days*2;
            if(cur>0){
                saved++;
                cur-=2;
                if(cur>0){
                    saved+=cur;
                    days++;
                }
                days++;
            }
        }
        cout<<n-saved<<endl;
    }
    return 0;
}