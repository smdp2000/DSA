class Solution {
public:
    
    
    
    int deleteAndEarn(vector<int>& nums) {
        int fn = *max_element(nums.begin(), nums.end())+1;
        vector<int>freq(fn);
        for(int i=0; i<nums.size();i++){
            freq[nums[i]] += nums[i];
        }
        
      //  for(int i=0; i<fn; i++)
       //     cout<<freq[i];
                        
        int cur=0, prev1=0, prev2=0;
        for(int i=0; i<fn; i++){
            
            cur = max(prev1+freq[i], prev2);
            prev1 = prev2;
            prev2 = cur;
        }
        
        return cur;
    }
};