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

bool check(vector<int>&a,int val){
    int i=0;int j=a.size()-1;
    while(i<j){
        while(a[i]==val){
            i++;
        }
        while(a[j]==val){
            j--;
        }
        if(i>=j){
            break;
        }
        if(a[i]!=a[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
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
        bool c=false;
        for(int i=0;i<n;i++){
            if(a[i]!=a[n-1-i]){
                if(check(a,a[i]) || check(a,a[n-1-i])){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
                c=true;
                break;
            }
        }
        if(c){
            continue;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}