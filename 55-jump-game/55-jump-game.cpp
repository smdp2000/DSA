class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxy = 0;
        for(int i=0; i<nums.size()-1 && i<=maxy; i++){
            maxy = max(maxy, nums[i]+i);
        }
        
        return maxy>=nums.size()-1;
    }
};