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
        long long n;
        cin>>n;
        vector<long long>a(n);
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        vector<int>ans;
        ans.push_back(a[0]);
        ans.push_back(a[1]);
        for(long long i=2;i<n;i++){
            long long s=ans.size();
            long long prev=ans[s-2]-ans[s-1];
            long long cur=ans[s-1]-a[i];
            if(prev>0){
                if(cur>0){
                    ans[s-1]=a[i];
                }
                else if(cur<0){
                    ans.push_back(a[i]);
                }
            }
            else{
                if(cur<0){
                    ans[s-1]=a[i];
                }
                else if(cur>0){
                    ans.push_back(a[i]);
                }
            }
        }
        long long val=ans.size();
        if(ans[0]==ans[1]){
            val--;
        }
        cout<<val<<endl;
    }
    return 0;
}