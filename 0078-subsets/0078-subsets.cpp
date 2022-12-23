class Solution {
public:
    
    void dfs(int i, vector<int>sub, vector<vector<int>>&subs, vector<int>&nums){
        
        if(i==nums.size()){
            subs.push_back(sub);
            return;
        }
        
        dfs(i+1, sub, subs, nums);
        sub.push_back(nums[i]);
        dfs(i+1,sub,subs,nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>sub;
        vector<vector<int>>subs;
        
        dfs(0,sub,subs,nums);
        
        return subs;
    }
};