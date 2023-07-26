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
        
        queue<int>q;
        
        q.push(n);
        int count = 0;
        while(!q.empty()){
            
            int layer_size = q.size();
            count++;
            for(int i=0; i<layer_size; i++){
                
                int m = q.front();
                
                
                for(int j=1; j*j<=m; j++){
                    
                    if(m-j*j==0)
                        return count;
                    if(m-j*j>0)
                        q.push(m-j*j);
                }
                
                q.pop();
            }
            
        }
        
        return count;
        
    }
};