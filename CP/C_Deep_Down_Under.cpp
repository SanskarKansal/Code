#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int sieve(int m, int n) {

    vector<bool> isPrime(n + 1, true);
    isPrime[0]  = false;
    
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> prefix(n+1, 0);
    for (int i = 1; i < n+1; ++i) {
        prefix[i] = prefix[i-1] + (isPrime[i]?1:0);
    }
    return prefix[n]-prefix[m-1];
}

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << sieve(l, r) << endl;
    }
    return 0;
}
