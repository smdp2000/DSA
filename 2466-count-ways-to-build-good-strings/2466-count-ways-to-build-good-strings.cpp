class Solution {
public:
    int MOD = 1000000007;
    
    long long getWays(int low, int high, int zero, int one, vector<int>&dp, int len){
        
        if(len>high) return 0;
        
        if(dp[len]!=-1) return dp[len];
        
        
        

        long long zway = getWays(low, high, zero, one, dp, len+zero);
        if(len+zero>=low && len+zero<=high) zway++;
        
        long long oway = getWays(low, high, zero, one, dp, len+one);
        if(len+one>=low && len+one<=high) oway++;
        
        return dp[len] = (zway+oway)%MOD;
        
        
        
        
        
            
    }
    
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int>dp(high+1, -1);
        
        return int(getWays(low, high, zero, one, dp, 0));
        
        
    }
};