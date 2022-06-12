class Solution {
public:
    
    int handlerob(vector<int>&nums, int l, int r){
        
         
        int rob1=0, rob2=0, cur=0;
        
        
        for(int i=l; i<=r; i++){
            //int temp = i;
            cur = max(rob2, rob1+nums[i] );
            rob1 = rob2;
            rob2 = cur;
        
        }
      
        return cur;
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==0)
            return 0;
        int n= nums.size();
        return max(handlerob(nums, 0, n-2), handlerob(nums, 1, n-1));
        
        
         
        
    }
};