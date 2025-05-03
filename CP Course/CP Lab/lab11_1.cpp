#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<int>>& a, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void dfs(int i, int j, int m, int n, vector<vector<int>>& vis, vector<vector<int>>& a, vector<pair<int, int>>& component) {
    vis[i][j] = 1;
    component.push_back({i, j});
    for(int k=i-1;k<=i+1;k++){
        for(int l=j-1;l<=j+1;l++){
            if(k>=0 && k<m && l>=0 && l<n && !vis[k][l] && a[k][l]){
                dfs(k,l,m,n,vis,a,component);
            }
        }
    }
}


int solve(vector<vector<int>>& a, int m, int n, vector<vector<pair<int, int>>>& path) {
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int count = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j] && a[i][j]) {
                path.push_back({});
                dfs(i, j, m, n, vis, a, path[count]);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> a(m, vector<int>(n));
        input(a, m, n);
        vector<vector<pair<int, int>>> path;
        int ans = solve(a, m, n, path);
        cout << ans << endl;
        for(auto& i : path) {
            for(auto& j : i) {
                cout << j.first << "-" << j.second << " ";
            }
            cout << endl;
        }
    }
}
/*
5
4 5
1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
3 3
1 1 1
0 1 0
0 0 1
2 3
0 1 0
1 1 0
5 5
1 0 0 1 0
0 0 1 0 0
1 0 1 1 0
0 0 0 1 0
0 1 1 1 1
4 4
1 1 0 0
1 1 0 0
0 0 1 1
0 0 0 1

#
2
0-0 0-1 1-1 2-0 
1-4 2-3 2-4 
1
0-0 0-1 0-2 1-1 2-2 
1
0-1 1-0 1-1 
3
0-0 
2-0 2-2 3-3 
4-1 4-2 4-3 4-4 
1
0-0 0-1 1-0 1-1 2-2 2-3 3-3 
*/