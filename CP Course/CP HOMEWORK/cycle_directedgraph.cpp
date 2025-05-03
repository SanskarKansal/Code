class Solution {
    public:
        vector<int> topologicalsort(int n, vector<vector<int>>& adj){
            vector<int>indegree(n,0);
            for(int i=0;i<n;i++){
                for(auto j:adj[i]){
                    indegree[j]++;
                }
            }
            queue<int>q;
            for(int i=0;i<n;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            vector<int>order;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                order.push_back(node);
                for(auto it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            }
            if(order.size()!=n){
                return {};
            }
            return order;
        }
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>>adj(numCourses);
            for(auto i: prerequisites){
                adj[i[1]].push_back(i[0]);
            }
            vector<int>ans=topologicalsort(numCourses,adj);
            return ans;
        }
    };