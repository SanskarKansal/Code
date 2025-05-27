#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long getArea(vector<pair<long long,long long>>& x, vector<pair<long long,long long>>& y, vector<pair<long long,long long>>& a, int Index) {
    vector<long long> xs, ys;
    for (int i = 0; i < a.size(); ++i) {
        if (i == Index) continue;
        xs.push_back(a[i].first);
        ys.push_back(a[i].second);
    }
    long long minx = *min_element(xs.begin(), xs.end());
    long long maxx = *max_element(xs.begin(), xs.end());
    long long miny = *min_element(ys.begin(), ys.end());
    long long maxy = *max_element(ys.begin(), ys.end());
    long long val= (maxx - minx+1) * (maxy - miny+1);
    if(val==a.size()){
        return min((maxx - minx+2) * (maxy - miny+1),(maxx - minx+1) * (maxy - miny+2));
    }
    return val;
}

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<long long,long long>> a(n), x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            x[i] = {a[i].first, i};
            y[i] = {a[i].second, i};
        }

        if (n <= 2) {
            cout << 0 << endl;
            continue;
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        long long ans = LLONG_MAX;

        ans = min(ans, getArea(x, y, a, x[n-1].second));

        ans = min(ans, getArea(x, y, a, x[0].second));

        ans = min(ans, getArea(x, y, a, y[n-1].second));

        ans = min(ans, getArea(x, y, a, y[0].second));

        cout << ans << endl;
    }
    return 0;
}
