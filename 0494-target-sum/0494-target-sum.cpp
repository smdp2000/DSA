class Solution {
public:
    int findways(int i, int target, vector<int>&nums, int n){
        
        
        if(i==n){
           if (target==0)
            return 1;
           else
               return 0;
    }
            
         int left = findways(i+1, target-nums[i], nums, n);
         int right = findways(i+1, target+nums[i], nums, n);
         return left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
      return findways(0, target, nums, nums.size());
        
    }
};