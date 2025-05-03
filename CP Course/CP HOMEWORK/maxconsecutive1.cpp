class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n=nums.size();
            int i=0;
            int count=0;
            int j=0;
            int maxm=0;
            while(i<n){
                if(nums[i]==0){
                    count++;
                }
                while(count>k){
                    if(nums[j]==0){
                        count--;
                    }
                    j++;
                }
                maxm=max(maxm,i-j+1);
                i++;
            }
            return maxm;
        }
    };