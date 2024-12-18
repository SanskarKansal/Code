#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int prim(int n,vector<vector<pair<int,int>>>& graph){
    vector<int>vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int>cost(n,INT_MAX);
    pq.push({0,0});
    cost[0]=0;
    int totalcost=0;
    while(!pq.empty()){
        int weight=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        totalcost+=weight;
        for(auto edge: graph[u]){
            int v=edge.first;
            int w=edge.second;
            if(!vis[v] && w<cost[v]){
                cost[v]=w;
                pq.push({w,v});
            }
        }
    }
    return totalcost;
}
int main(){
    vector<vector<pair<int,int>>>graph(6);

    graph[0].push_back({1,4});
    graph[1].push_back({0,4});
    
    graph[0].push_back({2,4});
    graph[2].push_back({0,4});

    graph[2].push_back({1,2});
    graph[1].push_back({2,2});

    graph[2].push_back({3,3});
    graph[3].push_back({2,3});

    graph[3].push_back({5,2});
    graph[5].push_back({3,2});

    graph[2].push_back({5,6});
    graph[5].push_back({2,6});

    graph[2].push_back({4,1});
    graph[4].push_back({2,1});

    graph[4].push_back({5,3});
    graph[5].push_back({4,3});


    cout<<"min spanning  tree is: "<<prim(6,graph);
}