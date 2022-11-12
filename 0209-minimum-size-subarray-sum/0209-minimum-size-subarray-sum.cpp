class Solution {
public:
    int minSubArrayLen(int target, vector<int>& s) {
        
        int cursum = 0;
        int j=0;
        int minl = 1e9;
        for(int i=0; i<s.size() ; i++){
            cursum = cursum + s[i];
            while(cursum>=target){
                minl = min(minl, i-j+1);
                cursum=cursum-s[j];
                j++;

            }   
            
            
        }
        
        return minl==1e9 ? 0 : minl;
        
    }
};