#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];

        vector<pair<long long, int>> topA, topB, topC;
        for (int i = 0; i < n; ++i) {
            topA.push_back({a[i], i});
            topB.push_back({b[i], i});
            topC.push_back({c[i], i});
        }

        sort(topA.rbegin(), topA.rend());
        sort(topB.rbegin(), topB.rend());
        sort(topC.rbegin(), topC.rend());

        int limit = 3;
        long long ans = 0;

        for (int i = 0; i < limit; ++i) {
            for (int j = 0; j < limit; ++j) {
                for (int k = 0; k < limit; ++k) {
                    int da = topA[i].second;
                    int db = topB[j].second;
                    int dc = topC[k].second;
                    if (da != db && db != dc && da != dc) {
                        long long total = topA[i].first + topB[j].first + topC[k].first;
                        ans = max(ans, total);
                    }
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
