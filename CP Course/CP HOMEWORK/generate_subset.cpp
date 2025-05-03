class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            int n=nums.size();
            int subset=1<<n;
            vector<vector<int>> powerset(subset);
            for(int i=0;i<subset;i++){
                for(int j=0;j<n;j++){
                    if(i&(1<<j)){
                        powerset[i].push_back(nums[j]);
                    }
                }
            }
            return powerset;
        }
    };