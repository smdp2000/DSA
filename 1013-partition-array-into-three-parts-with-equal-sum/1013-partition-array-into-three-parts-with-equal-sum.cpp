class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int sum=accumulate(begin(arr), end(arr), 0);
        if(sum%3)
                return false;
        
        int cur=0;
        int parts=0;
        int partsum = sum/3;
        for(int i=0; i<arr.size(); i++){
            
            cur+=arr[i];
            
            if(cur==partsum){
                cur=0;
                ++parts;
            }
            
        }
        
        return parts>=3;
        
        
      
    }
};