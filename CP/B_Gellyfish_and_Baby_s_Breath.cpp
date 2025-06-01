#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast_io();

    const long long MOD = 998244353;
    const long long MAXP = 100005;

    vector<long long> tpow(MAXP);
    tpow[0] = 1;
    for (long long i = 1; i < MAXP; i++) {
        tpow[i] = (tpow[i - 1] * 2) % MOD;
    }

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> p(n), q(n);
        for (long long i = 0; i < n; i++){
            cin>>p[i];
        }
        for (long long i = 0; i < n; i++){
            cin>>q[i];
        }
        vector<pair<long long, long long>> r(n);
        long long maxip = p[0];
        long long maxp = 0;
        long long maxiq = q[0];
        long long maxq = 0;
        for (long long i = 0; i < n; i++) {
            if (p[i] > maxip) {
                maxip = p[i];
                maxp = i;
            }
            if (q[i] > maxiq) {
                maxiq = q[i];
                maxq = i;
            }
            if (maxip > maxiq) {
                r[i].first = maxip;
                r[i].second = q[i - maxp];
            }
            else if (maxip == maxiq) {
                r[i].first = maxip;
                r[i].second = max(q[i - maxp], p[i - maxq]);
            }
            else {
                r[i].first = maxiq;
                r[i].second = p[i - maxq];
            }
        }

        for (long long i = 0; i < n; i++){
            cout << (tpow[r[i].first] + tpow[r[i].second]) % MOD << " ";
        }
        cout << endl;;
    }

    return 0;
}
