class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int product = 1;
            int mp = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            if(product == 0)
                product = 1;
            product = product*nums[i];
            mp = max(mp, product);
        }
       product = 1;
         for(int i=nums.size()-1; i>0; i--){
            if(product == 0)
                product = 1;
            product = product*nums[i];
            mp = max(mp, product);
        }
        
        return mp;
    }
};