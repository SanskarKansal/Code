#include <iostream>
#include<queue>
#include<vector>
using namespace std;

bool topoSort(vector<int>adj[],int v){
    vector<int>ans;
    vector<int>inDegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            inDegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<inDegree.size();i++){
        if(inDegree[i]==0)
        q.push(i);
    }
    while(!q.empty()){
        int elm=q.front();
        q.pop();
        ans.push_back(elm);
        for(auto it:adj[elm]){
            inDegree[it]--;
            if(inDegree[it]==0)
            q.push(it);
        }
    }
    if(ans.size()!=v)
    return true;
    return false ; 
}

int main(){
    vector<int>adj[4]={{1},{2},{3},{3}};
    int v=4;
    bool ans=topoSort(adj,v);
    cout << ans ;
}