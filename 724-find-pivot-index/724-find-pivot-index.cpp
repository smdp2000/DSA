class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>ps(nums.size(), 0);
        int leftsum = 0;
        
        for(int i=0; i<nums.size(); i++)
            leftsum += nums[i];
        int currsum=0;
        for(int i=0; i<nums.size(); i++){
            if(currsum == leftsum-nums[i])
                return i;
            else
            {
                leftsum-= nums[i];
                currsum+= nums[i];
            }
        }
        
        return -1;
    }
};