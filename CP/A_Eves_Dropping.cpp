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
    cin >> n;
    string x, y;
    cin >> x >> y;
    int maxi = 0;
    for (int shift = 0; shift < n; shift++) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (x[(i + shift) % n] == y[j]) dp[i+1][j+1] = 1 + dp[i][j];
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        maxi = max(maxi, dp[n][n]);
    }
    cout << maxi << endl;
    return 0;
}