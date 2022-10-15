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
    
    
    int bottomup(int n, vector<vector<int>>& matrix, vector<vector<int>>&dp)
    {
        
        for(int i=0; i<n; i++)
                dp[0][i] = matrix[0][i];
        
        for(int i=1; i<n; i++)
            for(int j=0; j<n; j++){
                int l=0,b=0,r=0;
               if(j>0) l += matrix[i][j] + dp[i-1][j-1];
                else l+=1e8;
                b += matrix[i][j] + dp[i-1][j];
                if(j<n-1) r += matrix[i][j] + dp[i-1][j+1]; 
                else r+= 1e8;
                int s = min(b,r);
                dp[i][j]=min(l, s);

            }
        int mini= 1e8;
        for(int i=0;i<matrix[0].size(); i++)
            mini = min(mini, dp[n-1][i]);
        
        return mini;
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int mini= INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n,-1));
        /*
        for(int i=0;i<matrix[0].size(); i++)
            mini = min(mini, getcost(0,i,n,matrix, dp));
       
        return mini;*/
        return bottomup(n, matrix, dp);

    }
};