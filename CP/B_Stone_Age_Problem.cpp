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
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>>a(n,{0,0});
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        sum+=a[i].first;
    }
    pair<int,int>glb={0,-1};
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        if(x==1){
            int ind,val;
            cin>>ind>>val;
            ind--;
            if(a[ind].second>glb.second){
                sum+=(val-a[ind].first);
            }
            else{
                sum+=val-glb.first;
            }
            a[ind].first=val;
            a[ind].second=i;
        }
        else{
            int val;
            cin>>val;
            glb.first=val;
            glb.second=i;
            sum=(long long)val*n;
        }
        cout<<sum<<endl;
    }
    return 0;
}