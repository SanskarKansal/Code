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
        int maxi = 1;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                maxi = max(maxi, a[i][j]);
            }
        }

        map<int, int> row, col;
        set<pair<int, int>> p;
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == maxi) {
                    row[i]++;
                    col[j]++;
                    p.insert({i, j});
                    count++;
                }
            }
        }

        bool check = false;
        for (auto i : row) {
            for (auto j : col) {
                int over = p.count({i.first, j.first});
                if (i.second + j.second - over == count) {
                    check = true;
                    break;
                }
            }
            if (check){
                break;
            }
        }

        if (check) {
            cout << maxi - 1 << endl;
        } else {
            cout << maxi << endl;
        }
    }
    return 0;
}
