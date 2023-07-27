class Solution {
public:
    
    int getScore(vector<int>& nums, int k, int i, vector<int>&dp){
        if(i==0)
            return nums[0];
        
        if(dp[i]!=-1)
            return dp[i];
        
      
        
        int maxscore = INT_MIN;
        
        for(int j=1; j<=k; j++){
            //cout<<nums[i]<<" "<<i<<" "<<j<<" "<<i-j<<endl;
            if(i-j>=0)
                maxscore = max(maxscore, nums[i]+getScore(nums, k, i-j,dp));
            //cout<<maxscore<<endl;
            }
        
        
        return dp[i] = maxscore;
        
    }
    int maxResult(vector<int>& nums, int k) {
        
        vector<int>dp(nums.size(), INT_MIN);
        
        
        priority_queue<pair<int,int>>pq;
        dp[0]=nums[0];
        pq.push({dp[0], 0});
        
        for(int i=1; i<nums.size(); i++){
            
          while(pq.size()&& pq.top().second < i-k)
              pq.pop();
            
        dp[i] = max(dp[i], nums[i]+dp[pq.top().second]);
        pq.push({dp[i],i});
            
        }
        
        return dp[nums.size()-1];
        
       
    }
};