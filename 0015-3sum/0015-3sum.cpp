class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i-1]==nums[i])
                continue;
            
            int l = i+1;
            int r= nums.size()-1;
            
            while(l<r){
                int sum = nums[i] + nums[l] +nums[r];
                if(sum > 0)
                    r--;
                else if(sum<0)
                    l++;
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(nums[l]==nums[l-1] && l<r)
                        l++;
                }
            }
        }
        
        
        
        return ans;
    }
};  