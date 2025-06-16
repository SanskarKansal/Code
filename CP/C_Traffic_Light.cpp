#include <bits/stdc++.h>
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
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        int ans = 0;

        if (c != 'g') {
            string s2 = s + s;
            int len = s2.length();
            vector<int> pos;
            for (int i = 0; i < len; i++) {
                if (s2[i] == 'g') pos.push_back(i);
            }

            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    auto it = upper_bound(pos.begin(), pos.end(), i);
                    if (it != pos.end()) {
                        ans = max(ans, *it - i);
                    }
                }
            }
        } else {
            ans = 0;
        }

        cout << ans << '\n';
    }
    return 0;
}
