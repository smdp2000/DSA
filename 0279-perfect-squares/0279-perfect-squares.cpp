class Solution {
public:
    
    int getWays(int n, vector<int>&dp){
        
        if(n==0){
            dp[0]=0;
            return 0;
        }
        
        if(dp[n]!=-1)
            return dp[n];
        
        
      //  int x = (int)sqrt(n);
        int numways = INT_MAX;
        for(int i=1; i*i<=n; i++){
            numways =  min(numways,1+getWays(n-i*i, dp));
        }
        
        return dp[n]=numways;
        
        
        
    }
    
    int numSquares(int n) {
        
      vector<int>dp(n+1,-1);
        
      return getWays(n, dp);
        
    }
};