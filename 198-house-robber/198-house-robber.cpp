class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0)
            return -1;
        
        if(nums.size()==1)
            return nums[0];
        
       
        
        int sumtl[nums.size()];
        
        sumtl[0] = nums[0];
        sumtl[1] = max(nums[0], nums[1]);
        
        
        for(int i=2; i<nums.size(); i++){
            sumtl[i] = max(sumtl[i-1] , nums[i]+sumtl[i-2]);      
        }
        
        return sumtl[nums.size()-1];
        
        
        
            
    }
};