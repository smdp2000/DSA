class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp;
        //int dp[nums.size()];
        dp.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++)
            dp.push_back(dp[i-1] + nums[i]);
        return dp;
    }
};