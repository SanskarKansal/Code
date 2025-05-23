#include <vector>
#include <iostream>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node]=1;
    for(auto it:adj[node]) {
        if(!vis[it]) dfs(it,adj,vis);
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) dfs(i,adj,vis);
    }
}
