#include <bits/stdc++.h>
using namespace std;

bool isFair(long long x) {
    long long temp = x;
    while (temp > 0) {
        int d = temp % 10;
        if (d != 0 && x % d != 0){
            return false;
        }
        temp /= 10;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        while (!isFair(n)){
            n++;
        }
        cout << n << '\n';
    }
    return 0;
}
