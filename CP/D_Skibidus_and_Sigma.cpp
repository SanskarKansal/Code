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
        int n;
        int m;
        cin>>n;
        cin>>m;
        vector<vector<int>>nums(n,vector<int>(m));
        vector<long long>val(n);
        long long ans=0;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<m;j++){
                cin>>nums[i][j];
                sum+=nums[i][j];
                ans+=sum;
            }
            val[i]=sum;
        }
        sort(val.begin(),val.end());
        long long k=0;
        for(int i=0;i<n;i++){
            ans+=k*val[i];
            k+=m;
        }
        cout<<ans<<endl;
    }
    return 0;
}