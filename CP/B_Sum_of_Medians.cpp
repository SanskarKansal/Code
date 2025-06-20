#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n * k);
        for (int i = 0; i < n * k; i++) {
            cin >> a[i];
        }

        int take = n / 2 + 1;
        long long ans = 0;
        int index = n * k - take;
        for (int i = 0; i < k; i++) {
            ans += a[index];
            index -= take;
        }

        cout << ans << endl;
    }
    return 0;
}
