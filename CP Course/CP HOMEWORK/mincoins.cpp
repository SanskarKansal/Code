class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            vector<int>mincoins(amount+1,amount+1);
            mincoins[0]=0;
            for(int i=1;i<=amount;i++){
                for(int coin: coins){
                    if(i>=coin){
                        mincoins[i]=min(mincoins[i],mincoins[i-coin]+1);
                    }
                }
            }
            if(mincoins[amount]>amount){
                return -1;
            }
            return mincoins[amount];
        }
    };