#include <iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(int i ,vector<int>&vis , stack<int>&st,vector<int>adj[]){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it])
        dfs(it,vis,st,adj);
    }
    st.push(i);
}
vector<int> topoSort(vector<int>adj[],int v){
    vector<int>vis(v,0);
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;

}

int main(){
    int v=6;
    vector<int>adj[6]={{},{3},{3},{},{0,1},{0,2}};
    vector<int>out=topoSort(adj,v);
    for(int i=0;i<out.size();i++){
        cout << out[i] << " ";
    }
}