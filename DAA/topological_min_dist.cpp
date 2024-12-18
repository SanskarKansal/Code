#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<bool>& vis, stack<int>& st, vector<pair<int, int>> adj[]) {
    vis[node] = true;
    for (auto it : adj[node]) {
        int adjNode = it.first;
        if (!vis[adjNode]) {
            dfs(adjNode, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int src, int v, vector<pair<int, int>> adj[]) {
    vector<bool> vis(v, false);
    stack<int> st;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (dist[node] != INT_MAX) { 
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;
                if (dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                }
            }
        }
    }
    return dist;
}

int main() {
    int v = 6; 
    vector<pair<int, int>> adj[6];
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[4].push_back({2, 2});
    adj[4].push_back({5, 4});
    adj[2].push_back({3, 6});
    adj[5].push_back({3, 1});
    int src = 0;
    vector<int> distances = shortestPath(src, v, adj);
    cout << "Shortest distances: " << src << ":\n";
    for (int i = 0; i < v; i++) {
        if (distances[i] == INT_MAX) {
            cout << "Node " << i << ": Unreachable "<<endl;
        } else {
            cout << "Node " << i << ": " << distances[i] << "\n";
        }
    }
}