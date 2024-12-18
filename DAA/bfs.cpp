#include <bits/stdc++.h>
using namespace std;

void bfs(int start, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> vis;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        vis[i] = false;
    }
    int start;
    cin >> start;
    bfs(start, adj, vis);
}