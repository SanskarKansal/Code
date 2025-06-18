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
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        int val=-1;
        for(auto i:mp){
            if(i.second==1){
                val=i.first;
                break;
            }
        }
        if(val==-1){
            cout<<"NO"<<endl;
        }
        else{
            sort(a.rbegin(),a.rend());
            vector<int>b(n);
            b[0]=val;
            int j=0;
            for(int i=1;i<n;i++){
                if(a[j]==val){
                    j++;
                }
                b[i]=a[j];
                j++;
            }
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<b[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}