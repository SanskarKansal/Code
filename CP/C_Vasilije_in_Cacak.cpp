#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;

        long double mini = (long double)(k) * (k + 1) / 2.0;
        long double maxi = (long double)(n) * (n + 1) / 2.0 - (long double)(n - k) * (n - k + 1) / 2.0;

        if (x >= mini && x <= maxi) cout << "YES"<<endl;
        else cout << "NO"<<endl;;
    }
    return 0;
}
