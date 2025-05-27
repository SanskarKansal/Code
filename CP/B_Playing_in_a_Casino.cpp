#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> a(m, vector<long long>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[j][i];
            }
        }

        long long ans = 0;
        if (n == 1) {
            cout << 0 << endl;
        }
        else {
            for (int i = 0; i < m; i++) {
                sort(a[i].begin(), a[i].end());
                for(int j = 0; j < n; j++) {
                    ans +=a[i][j]*(2*j-n+1);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
