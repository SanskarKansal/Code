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
        cin>>n;
        vector<long long>a(n);
        vector<long long>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vector<pair<long long ,long long>>val(n);
        for(int i=0;i<n;i++){
            val[i].first=a[i]-b[i];
            val[i].second=i;
        }
        sort(val.begin(),val.end());
        vector<long long>res;
        res.push_back(val[n-1].second);
        int i=n-2;
        while(i>=0 && val[i].first==val[i+1].first){
            res.push_back(val[i].second);
            i--;
        }
        sort(res.begin(),res.end());
        cout<<res.size()<<endl;
        for( i=0;i<res.size();i++){
            cout<<res[i]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}