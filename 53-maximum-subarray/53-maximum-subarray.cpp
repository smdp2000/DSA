class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        
        int cursum =0, curmax=nums[0];
        
        for(auto i : nums){
            if(cursum<0)
                cursum=0;
            cursum += i;
            curmax= max(curmax, cursum);
        }
        /*working second approach
        int maxfr = nums[0];
        int maxher = nums[0];
        for(int i=1; i<nums.size(); i++){
            maxher = max(nums[i], nums[i]+maxher);
            maxfr = max(maxfr, maxher);
            
        }
        
        return maxfr;*/
        return curmax;
     
    }
};