class Solution {
public:
    
    long long getPoints(vector<vector<int>>& questions, vector<long long>&dp, int ind){
        
        if(ind>=questions.size())
            return 0;
            
        if(dp[ind]!=-1)
            return dp[ind];
    
        
             
        long long take = questions[ind][0] + getPoints(questions, dp, ind+questions[ind][1]+1);
            
        long long nottake  = getPoints(questions, dp, ind+1);
    
        
        
        return dp[ind] = max(take, nottake);
        
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        
        
        vector<long long>dp(questions.size(),-1);
        
        return getPoints(questions, dp, 0);
    }
};