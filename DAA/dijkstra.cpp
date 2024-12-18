#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];
            if (weight + w < dist[v])
            {
                dist[v] = weight + w;
                pq.push({weight + w, v});
            }
        }
    }
    return dist;
}

int main()
{
   int V = 5, E = 6, S = 0;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({0, 4});
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 3});
    adj[3].push_back({1, 7});
    adj[3].push_back({2, 3});
    adj[3].push_back({4, 5});
    adj[4].push_back({3, 5});
    vector<int> result = dijkstra(V, adj, S);
    for (int i = 0; i < V; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
