#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0);

int main(){
    fastIO;
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        long long i = -1;
        for(long long r = 1; r <= n; r++){
            long long mini = (n - 1) + r;
            long long maxi = r * (r + 1) / 2 + (n - r) * r;
            if (m >= mini && m <= maxi){
                i = r;
                break;
            }
        }

        if (i < 0) {
            cout << "-1\n";
            continue;
        }

        cout << i << "\n";

        vector<int> p(n+1, 0);
        for(int x = i; x > 1; x--){
            p[x-1] = x;
        }
        for(int v = i+1; v <= n; v++){
            p[v] = 1;
        }

        long long mind = (n - 1) + i;
        long long rem = m - mind;

        for(int v = i+1; v <= n && rem > 0; v++){
            long long g = i - 1;
            if (rem >= g) {
                p[v] = i;
                rem -= g;
            } else {
                int u = i - rem;
                p[v] = u;
                rem = 0;
            }
        }

        for(int v = 1; v <= n; v++){
            if (v == i) continue;
            cout << p[v] << " " << v << "\n";
        }
    }
    return 0;
}