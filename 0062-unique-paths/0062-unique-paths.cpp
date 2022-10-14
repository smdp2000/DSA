class Solution {
public:
    
    int paths(int i, int j, int m, int n, vector<vector<int>>&dp){
        
        dp[0][0] = 1;
        
        for(int i=1; i<m ; i++)
            for(int j=1; j<n; j++){
                int r = dp[i-1][j];
                int b = dp[i][j-1];
                dp[i][j]=r+b;
            }
        
        return dp[m-1][n-1];
        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,1));
        return paths(0, 0, m, n, dp);
        
    }
    /*
    if(i==m-1 && j==n-1)
                return 1;
        if(i>=m  || j>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int r = paths(i+1, j, m, n, dp);
       
        int b = paths(i, j+1, m, n, dp);
        
        return dp[i][j] =  r+b;
    
    */
};