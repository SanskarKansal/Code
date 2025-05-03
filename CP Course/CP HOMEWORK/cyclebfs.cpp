#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void input(vector<vector<int>> &graph, int v) {
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
}

bool cyclePresenceTopo(vector<vector<int>> &graph, int v) {
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (int it : graph[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;

        for (int it : graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return cnt != v;
}

bool dfsHelp(vector<vector<int>>& graph, int x, vector<bool> &vis, vector<bool> &pathvis) {
    vis[x] = true;
    pathvis[x] = true;
    
    for (int it : graph[x]) {
        if (!vis[it]) {
            if (dfsHelp(graph, it, vis, pathvis)) return true;
        } else if (pathvis[it]) {
            return true;
        }
    }
    
    pathvis[x] = false;
    return false;
}

bool cyclePresenceDFS(vector<vector<int>>& graph, int v) {
    vector<bool> vis(v, false);
    vector<bool> pathvis(v, false);
    
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            if (dfsHelp(graph, i, vis, pathvis)) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v;
        cin >> v;
        vector<vector<int>> graph(v);
        input(graph, v);

        bool isCyclicTopo = cyclePresenceTopo(graph, v);
        cout << isCyclicTopo << endl;
        
        bool isCyclicDFS = cyclePresenceDFS(graph, v);
        cout << isCyclicDFS << endl;

        cout << endl;
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