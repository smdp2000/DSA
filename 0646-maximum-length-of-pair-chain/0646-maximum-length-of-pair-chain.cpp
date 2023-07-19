    bool cmp (vector<int>a, vector<int>b){
        
        return a[1]<b[1];
        
    }
class Solution {
public:
    

    int findLongestChain(vector<vector<int>>& pairs) {
        // [[1,2],[7,8],[4,5]]
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int>dp(pairs.size(),1);
        
        int n = pairs.size();
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                
                if(pairs[i][0]>pairs[j][1] && dp[i]<dp[j]+1){
                    
                    dp[i] = 1+dp[j];
                    
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};