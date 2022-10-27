class Solution {
public:
    int helper(vector<int>& coins, int amount, int i, vector<vector<int>>&dp){
        if (amount<=0)
            return 0;
 
        if (amount!=0 && i>coins.size()-1)
            return 1e8;
        
        int res = -1;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        if(amount<coins[i])
        {
            dp[i][amount] = 0+helper(coins, amount, i+1, dp);
        }
        else{
            dp[i][amount]=min(1+helper(coins, amount-coins[i], i, dp), 0+helper(coins, amount, i+1, dp));
            
        }  
                    return dp[i][amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int res = helper(coins, amount, 0, dp);
        return res==1e8?-1:res;
        
    }
};