class Solution {
public:
    
    int getWays(int floors, int eggs, vector<vector<int>>&dp){
        
        if(floors==1 or floors==0){
            return floors;
        }
        
           
       if( eggs == 1 ){
           return floors;
       }
        
        if(dp[eggs][floors]!=-1){
            return dp[eggs][floors];
        }
        
        int miny=INT_MAX;
        for(int i=1; i<=floors; i++){
            miny = min( miny, 1+max( getWays(floors-i,eggs,dp), getWays(i-1,eggs-1,dp) ) );
            
        }
        
        return dp[eggs][floors]=miny;
        
    }
    
    int twoEggDrop(int n) {
        
        int eggs=2;
        vector<vector<int>>dp(eggs+1,vector<int>(n+1,-1));
        return getWays(n, eggs, dp);
    }
};