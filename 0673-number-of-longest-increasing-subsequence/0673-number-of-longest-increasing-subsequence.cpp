class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        vector<int>count(nums.size(),1);
        vector<int>dp(nums.size(),1);
        int n=nums.size();
        int maxl = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++ )
            {
                if(nums[j]>nums[i] ){
                    
                    if(dp[i]<1+dp[j]){
                        
                        dp[i] = 1+dp[j];
                    count[i] = count[j];
                        
                    }
                    
                    else if(dp[i]==1+dp[j])
                            count[i] += count[j];
                    

                    
                }
                
                if(maxl<dp[i])
                    maxl = dp[i];
                
                
            }
        }
        
        
        int ans=0;
        
        for(int i=0; i<count.size(); i++){
            if(maxl==dp[i])
                ans+=count[i];
        }
        
        return ans;
        
    }
};