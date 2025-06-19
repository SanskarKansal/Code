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
        string s;
        cin>>s;
        string a;
        cin>>a;
        int j=a.size()-1;
        map<char,int>mp;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        for(int i=s.size()-1;i>=0;i--){
            if(j<0){
                break;
            }
            if(s[i]==a[j]){
                mp[a[j]]--;
                j--;
            }
            else if(mp[s[i]]>0){
                break;
            }
        }
        if(j<0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}