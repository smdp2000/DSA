class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        
        unordered_map<int, int> dp;
        int maxy=0;
        
        for(int i=0; i<n; i++){
                
            dp[arr[i]]=dp[arr[i]-difference]+1;
            maxy = max(maxy, dp[arr[i]]);
        }
     
        
                    return maxy;

    }
        
    
};