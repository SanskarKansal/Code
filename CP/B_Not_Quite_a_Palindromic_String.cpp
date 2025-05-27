#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int zero = 0, one = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zero++;
            else one++;
        }

        int diff = abs(zero - one);

        if (diff > (2 * k + 1)) {
            cout << "No" << endl;
        } else {
            if (diff - 2 * k >= 0) {
                cout << "Yes" << endl;
            } else {
                int val = 2 * k - diff;
                val %= 4;
                if (val == 2 || val == 3) {
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
            }
        }
    }
    return 0;
}
