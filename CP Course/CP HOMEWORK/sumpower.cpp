#include <bits/stdc++.h>
using namespace std;

long long flips(int n, int k, string& s) {
    long long cnt = 0;
    int i;
    for (i = 0; i < n - k; i++) {
        if (s[i] != s[i + 1]) cnt++;
    }
    int prevCnt = cnt;
    while (i < n - 1) {
        if (s[i - (n - k)] != s[i - (n - k) + 1]) prevCnt--;
        if (s[i] != s[i + 1]) prevCnt++;
        i++;
        cnt += prevCnt;
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << flips(n, k, s) << endl;
    }
    return 0;
}
