class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        int dup;
        
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end())
                
                dup = nums[i];
            
            else
                mp[nums[i]] = 1;
            
        }
            
        return dup;
        
    }
};