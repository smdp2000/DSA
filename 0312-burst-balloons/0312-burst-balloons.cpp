class Solution {
public:
    int findmax(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int max_cost=INT_MIN;
        for(int ind= i; ind<=j; ind++){
            int cost = nums[i-1]*nums[ind]*nums[j+1]
                       + findmax(i, ind-1, nums, dp) + findmax(ind+1, j, nums, dp);
            max_cost = max(max_cost, cost);
        }
        return dp[i][j] = max_cost;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        
        return findmax(1,n, nums, dp);
        
    }
};