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
        int minvalue=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int minperfectsquarepro=getWays(n-i*i,dp);
            minvalue=min(minvalue,minperfectsquarepro+1);
        }
        
        return dp[n]=minvalue;
        
        
        
    }
    
    int numSquares(int n) {
        
      vector<int>dp(n+1,-1);
        
      return getWays(n, dp);
        
    }
};