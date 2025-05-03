class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            int n=prerequisites.size();
            vector<int>vis(numCourses,0);
            vector<int>degree(numCourses,0);
            vector<vector<int>>adj(numCourses);
            for(int i=0;i<n;i++){
                degree[prerequisites[i][1]]++;
                adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
            queue<int>q;
            for(int i=0;i<numCourses;i++){
                if(degree[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
            int count=0;
            while(!q.empty()){
                int val=q.front();
                q.pop();
                count++;
                for(auto j: adj[val]){
                    degree[j]--;
                    if(!vis[j]  && degree[j]==0){
                        vis[j]=1;
                        q.push(j);
                    }
                }
            }
            return count==numCourses;
        }
    };