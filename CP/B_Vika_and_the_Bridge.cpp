#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];

        vector<vector<int>> pos(k + 1);
        for (int i = 0; i < n; i++){
            pos[c[i]].push_back(i);
        }

        int ans = n;
        for (int color = 1; color <= k; color++) {
            if (pos[color].empty()){
                continue;
            }
            vector<int> gaps;
            gaps.push_back(pos[color][0]); 
            for (int i = 1; i < pos[color].size(); i++) {
                gaps.push_back(pos[color][i] - pos[color][i - 1] - 1);
            }
            gaps.push_back(n - 1 - pos[color].back());
            sort(gaps.begin(), gaps.end());
            int sz = gaps.size();
            int largest = gaps[sz - 1];
            int second = (sz >= 2 ? gaps[sz - 2] : 0);
            int worst = max(second, (largest) / 2);
            ans = min(ans, worst);
        }

        cout << ans << '\n';
    }
    return 0;
}
