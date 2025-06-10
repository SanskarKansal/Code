#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long a = -1, b = -1, c = -1;
        
        for (long long i = 2; i * i * i <= n; i++) {
            if (n % i == 0) {
                a = i;
                break;
            }
        }

        if (a == -1) {
            cout << "NO" << endl;
            continue;
        }

        long long rem = n / a;
        for (long long i = a + 1; i * i <= rem; i++) {
            if (rem % i == 0) {
                b = i;
                c = rem / b;
                break;
            }
        }

        if (c > 1 && b != c ) {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
