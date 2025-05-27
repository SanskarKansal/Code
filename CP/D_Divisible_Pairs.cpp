#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        map<long long, map<long long, int>> mp;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long modx = ((-a[i]) % x + x) % x;
            long long mody = a[i] % y;
            if (mp.count(modx) && mp[modx].count(mody)) {
                ans += mp[modx][mody];
            }
            mp[a[i] % x][a[i] % y]++;
        }
        cout << ans << '\n';
    }
    return 0;
}