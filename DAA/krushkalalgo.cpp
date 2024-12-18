#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findParent(int u, vector<int>& parent) {
    if (u == parent[u]){
        return u;
    }
    return parent[u] = findParent(parent[u], parent);
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]){
            swap(u, v);
        }
        parent[v] = u;
        if (rank[u] == rank[v]){
            rank[u]++;
        }
    }
}

vector<vector<int>> kruskal(int n, vector<vector<pair<int, int>>>& graph) {
    vector<vector<int>> edges;
    vector<vector<int>> result;
    for (int u = 0; u < n; ++u) {
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (u < v){
                edges.push_back({u, v, weight});
            }
        }
    }
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++){
        parent[i] = i;
    }
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if (findParent(u, parent) != findParent(v, parent)) {
            result.push_back({u, v, weight});
            unionSets(u, v, parent, rank);
        }
    }
    return result;
}

int main() {
    vector<vector<pair<int, int>>> graph(5);

    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});

    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});

    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});

    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    vector<vector<int>> ans = kruskal(5, graph);
    cout << "Applying Kruskal's algorithm: " << endl;
    for (auto& edge : ans) {
        cout << edge[0] << " - " << edge[1] << " with weight " << edge[2] << endl;
    }
}
