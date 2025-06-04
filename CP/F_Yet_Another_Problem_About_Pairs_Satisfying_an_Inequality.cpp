#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val <= i) {
                v.push_back({val, i + 1});
            }
        }

        if (v.empty()) {
            cout << 0 << endl;
            continue;
        }

        vector<int> idx;
        long long ans = 0;
        for (int i = 0; i < v.size(); i++) {
            int count = lower_bound(idx.begin(), idx.end(), v[i].first) - idx.begin();
            ans += count;
            idx.push_back(v[i].second);
        }

        cout << ans << endl;
    }
    return 0;
}
