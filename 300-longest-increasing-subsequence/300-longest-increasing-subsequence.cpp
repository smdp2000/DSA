class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>LS(nums.size(), 1);
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i]<nums[j]){
                    LS[i] = max(LS[i],1+LS[j]);
                }
            }
        }
        
        return *max_element(LS.begin(), LS.end());
    }
};