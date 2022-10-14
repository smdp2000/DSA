class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,1));
         for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){

                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;}
                else if (i==0 && j==0) dp[i][j] = 1;
                else{
                int r=0,b=0;
                if(i>0) r = dp[i-1][j];
                if(j>0) b = dp[i][j-1];
                    dp[i][j]=r+b;

                }

            }
            // cout<<endl;
         }   
       // cout<<dp[m-1][n-1];
        return dp[m-1][n-1];  
    }
};

/* 

 int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(obstacleGrid[i][j] == 1)
                    {
                            obstacleGrid[i][j]  = 0;
                    }
                    else if (i==0 && j==0) obstacleGrid[i][j] = 1;      
                    else
                    {
                        int left=0, right=0;
                        if(i>0) left = obstacleGrid[i-1][j];
                        if(j>0) right = obstacleGrid[i][j-1];
                        obstacleGrid[i][j] = left + right;
                    }
                    
                }
                        
            }
        
        return obstacleGrid[m-1][n-1];


*/