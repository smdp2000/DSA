class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        //keep count of+ve and -ve
        int ans=0,neg=0,pos=0;
        for(auto i:nums){
            if(i>0)
            {
                pos++;
                neg = neg>0 ? neg+1 : 0;
            }
            else if(i<0){
            int temp =pos;
             pos = neg>0 ? neg+1 : 0;
             neg = temp+1;
            }
            else{
                pos=0;
                neg=0;
        }
            ans = max(ans, pos);
        }
        
        
        return ans;
    }
};