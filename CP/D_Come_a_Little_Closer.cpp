#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int n;

ll getArea(int mn_x, int mx_x, int mn_y, int mx_y) {
	ll h = mx_x - mn_x + 1, w = mx_y - mn_y + 1;
	if(h*w < n) return min((h+1)*w, h*(w+1));
	return h*w;
}

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> x(n), y(n);
        for (int i = 0; i < n; i++) {
            int xi, yi;
            cin >> xi >> yi;
            x[i] = {xi, i};
            y[i] = {yi, i};
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll ans = getArea(x[0].first, x[n-1].first, y[0].first, y[n-1].first);

        if (n == 1) {
            cout << ans << '\n';
            continue;
        }

        set<int> indices = {x[0].second, x[n-1].second, y[0].second, y[n-1].second};
        for (int i : indices) {
            int mnx = x[0].second == i ? x[1].first : x[0].first;
            int mxx = x[n-1].second == i ? x[n-2].first : x[n-1].first;
            int mny = y[0].second == i ? y[1].first : y[0].first;
            int mxy = y[n-1].second == i ? y[n-2].first : y[n-1].first;

            ans = min(ans, getArea(mnx, mxx, mny, mxy));
        }

        cout << ans << '\n';
    }
    return 0;
}
