#include <bits/stdc++.h>
using namespace std;

long long manhattan(pair<long long, long long> a, pair<long long, long long> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        --a; --b;
        vector<pair<long long, long long>> coords(n);
        for (int i = 0; i < n; ++i) {
            cin >> coords[i].first >> coords[i].second;
        }

        if (a < k && b < k) {
            cout << "0\n";
            continue;
        }

        long long cost_direct = manhattan(coords[a], coords[b]);

        if (k == 0) {
            cout << cost_direct << '\n';
            continue;
        }

        long long minA = LLONG_MAX, minB = LLONG_MAX;
        for (int i = 0; i < k; ++i) {
            minA = min(minA, manhattan(coords[a], coords[i]));
            minB = min(minB, manhattan(coords[b], coords[i]));
        }

        cout << min(cost_direct, minA + minB) << '\n';
    }
    return 0;
}
