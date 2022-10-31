class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        int n=s.length();
        reverse(s.begin(), s.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==0||j==0){
                    dp[i][j]=0; 
                }
            }
        }
        
         
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s2[i-1]==s[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
};