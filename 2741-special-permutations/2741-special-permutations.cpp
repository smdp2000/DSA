class Solution {
public:
    int mod=1000000007;
    int getPermutations(vector<vector<int>>&dp, vector<int>&nums, int prev, int cur, int mask){
        
        if(cur == nums.size())
            return 1;
        
        if(dp[prev+1][mask]!=-1)
            return dp[prev+1][mask];
            
            int ans=0;
        for(int j=0; j<nums.size(); j++){
            
            if((mask & (1<<j)) > 0)
                continue;
            
            if(prev==-1 || nums[j]%nums[prev] ==0 || nums[prev]%nums[j]==0)
                ans = (ans + getPermutations(dp, nums, j, cur+1, mask| (1<<j)))%mod;            
            
        }
        
        return dp[prev+1][mask] = ans;
        
    }
    
    int specialPerm(vector<int>& nums) {
        
        vector<vector<int>>dp(nums.size()+1,vector<int>((1<<14)+1, -1));
        
        return getPermutations(dp, nums, -1, 0, 0);
        
    }
};