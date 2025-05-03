class Solution {
    public:
        bool iterate(int ind,int target,vector<int> &nums, vector<vector<int>> &dp){
            if(target==0){
                return true;
            }
            if(ind==0){
                return nums[0]==target;
            }
            if(dp[ind][target] != -1){
                return dp[ind][target];
            }
            bool nottaken =iterate(ind-1,target,nums,dp);
            bool taken=false;
            if(nums[ind]<=target){
                taken=iterate(ind-1,target-nums[ind],nums,dp);
            }
            return dp[ind][target]=nottaken || taken;
        }
        bool canPartition(vector<int>& nums) {
            int sum=0;
            int n=nums.size();
            for(int i=0;i<n;i++){
                sum+=nums[i];
            }
            if(sum%2){
                return false;
            }
            else{
                sum=sum/2;
                vector<vector<int>>dp(n,vector<int>(sum+1,-1));
                return iterate(n-1,sum,nums,dp);
            }
        }
    };