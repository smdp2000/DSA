class Solution {
public:
    
    int getcost(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        
        if(j>=matrix[0].size()|| j<0 ) return 1e8;
        if (i==n-1)
                return   matrix[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        cout<<i<<j<<endl;
        int l = matrix[i][j] + getcost(i+1, j-1, n, matrix, dp);
        int b = matrix[i][j] + getcost(i+1, j, n, matrix, dp);
        int r = matrix[i][j] + getcost(i+1, j+1, n, matrix, dp);
        int s = min(b,r);
        return dp[i][j]=min(l, s);
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int mini= INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int i=0;i<matrix[0].size(); i++)
            mini = min(mini, getcost(0,i,n,matrix, dp));
       
        return mini;

    }
};