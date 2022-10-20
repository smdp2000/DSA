class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int S=accumulate(begin(nums), end(nums), 0);
     // cout<<S<<endl;
        if(S%2==0)
            return getsum(S/2, nums);
        return false;
       
    }
    
    
    bool getsum(int s, vector<int>&nums)
    {   //cout<<s;
        
        int n= nums.size();
  //   cout<<n;
        vector<vector<bool>>dp(nums.size(), vector<bool>(s+1,0));
     //   cout<<dp.size();
     for(int i=0;i<n; i++) 
         dp[i][0] =   true;
   // cout<<"hel";
    
    if(nums[0]<=s) dp[0][nums[0]]=true;
  //   cout<<dp.size();
       for(int i=1;i<n;i++){
           for(int tg=1; tg<=s; tg++){
                     //  cout<<i<<tg<<endl;
               bool nottake=dp[i-1][tg];
               bool take= false;
               if(tg>=nums[i])
                       take= dp[i-1][tg-nums[i]];
               dp[i][tg] = take|nottake;
           }
       }
     
     return dp[n-1][s];
    }
};