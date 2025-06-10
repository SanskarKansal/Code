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
    int n;
    cin>>n;
    vector<long long>a(n);
    unordered_map<long long,long long>mp;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        mp[a[i]]++;
    }
    long long ans=0;
    vector<long long>val;
    for(int i=0;i<n;i++){
        long long num=sum-a[i];
        if(num%2==0 && mp.find((num)/2)!=mp.end()){
            if(num/2==a[i] && mp[a[i]]<=1){
                continue;
            }
            ans++;
            val.push_back(i+1);
        }
    }
    cout<<ans<<endl;
    for(auto i: val){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}