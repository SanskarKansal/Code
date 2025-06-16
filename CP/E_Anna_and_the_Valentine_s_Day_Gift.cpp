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
        vector<int>a;
        long long sum=0;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            long long count=0;
            while(num>0 && num%10==0){
                num/=10;
                count++;
            }
            if(count>0){
                a.push_back(count);
            }
            count=0;
            while(num>0){
                num/=10;
                count++;
            }
            sum+=count;
        }
        if(sum>m){
            cout<<"Sasha"<<endl;
        }
        else{
            sort(a.begin(),a.end());
            int l=a.size();
            for(int i=a.size()-2;i>=0;i-=2){
                sum+=a[i];
            }
            if(sum>m){
                cout<<"Sasha"<<endl;
            }
            else{
                cout<<"Anna"<<endl;
            }
        }
    }
    return 0;
}