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
        unordered_map<int,int>mp;
        vector<vector<int>>val(n);
        for(int i=0;i<n;i++){
            int bits;
            cin>>bits;
            while(bits--){
                int pos;
                cin>>pos;
                mp[pos]++;
                val[i].push_back(pos);
            }
        }
        bool p=false;
        for(int i=0;i<n;i++){
            bool check=true;
            for(int j=0;j<val[i].size();j++){
                if(mp[val[i][j]]==1){
                    check=false;
                    break;
                }
            }
            if(check){
                cout<<"YES"<<endl;
                p=true;
                break;
            }
        }
        if(!p){
            cout<<"NO"<<endl;
        }

    }
    return 0;
}