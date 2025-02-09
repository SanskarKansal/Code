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
        // Code for each test 
        int n;
        int m;
        cin>>n;
        cin>>m;
        vector<long long>a(n);
        vector<long long> b(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        if(b[m-1]-a[n-1]>a[n-1]){
            a[n-1]=b[m-1]-a[n-1];
        }
        int check=0;
        for(int i=n-2;i>=0;i--){
            int start=0;
            int end=m-1;
            int val=-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(b[mid]-a[i]==a[i+1]){
                    a[i]=b[mid]-a[i];
              
                    break;
                }
                if(b[mid]-a[i]<a[i+1]){
                    a[i]=max(a[i],b[mid]-a[i]);
                    val=mid;
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            if(val!=-1 && a[i]>a[i+1]){
                a[i]=b[val]-a[i];
            }
            if(a[i]>a[i+1]){
                cout<<"NO"<<endl;
                check++;
                break;
            }
        }
        if(!check){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}