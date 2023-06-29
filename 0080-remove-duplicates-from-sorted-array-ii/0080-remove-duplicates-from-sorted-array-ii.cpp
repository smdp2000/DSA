class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        
        int l=0, r=0;
        
        while (r<nums.size()){
                int count=1;
            while (r+1<nums.size() && nums[r]==nums[r+1]){
                r+=1;
                count+=1;
            }

            
            count = min(2,count);
            
            for(int j=0; j<count; j++)
                nums[l++] = nums[r];
            
            r++;
        }
        
        
        return l;
        
        
    }
};