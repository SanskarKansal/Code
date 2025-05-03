#include <bits/stdc++.h>
using namespace std;

bool topo(vector<vector<int>> &adj, int v) {
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return count != v;
}

void input(vector<vector<int>> &adj, int e) {
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> adj(v);
        input(adj, e);
        bool hasCycle = topo(adj, v);
        cout << hasCycle << endl;
    }
}
/*
3
4 4
0 1
1 2
2 3
3 1
3 2
0 1
1 2
4 3
0 1
1 2
2 3
#
1
0
0
*/
