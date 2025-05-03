class Solution {
    public:
        int operations(int i,int j,string &s,string &t,vector<vector<int>> &dp){
            if(i<0){
                return j+1;
            }
            if(j<0){
                return i+1;
            }
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            if(s[i]==t[j]){
                return dp[i][j]=operations(i-1,j-1,s,t,dp);
            }
            else{
                int ins=operations(i-1,j,s,t,dp);
                int del=operations(i,j-1,s,t,dp);
                int rep=operations(i-1,j-1,s,t,dp);
                return dp[i][j]=1+min({ins,del,rep});
            }
        }
        int minDistance(string word1, string word2) {
            int m=word1.length();
            int n=word2.length();
            vector<vector<int>>dp(m,vector<int>(n,-1));
            return operations(m-1,n-1,word1,word2,dp);
        }
    };