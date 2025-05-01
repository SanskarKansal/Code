#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void bfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto it:adj[u]) {
            if(!vis[it]) {
                vis[it]=1;
                q.push(it);
            }
        }
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
        if(!vis[i]) bfs(i,adj,vis);
    }
}
