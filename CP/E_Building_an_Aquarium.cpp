#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<long long> a(n);
        long long high = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            high = max(high, a[i]);
        }

        long long low = 1;
        high += x + 1;

        long long ans = -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = 0;
            for (int i = 0; i < n; i++) {
                if (mid > a[i]) val += mid - a[i];
                if (val > x) break;
            }
            if (val <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
