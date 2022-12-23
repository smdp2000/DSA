class Solution {
public:
    bool isMatch(string s, string p) {
                vector<vector<int>> dp(s.length()+1,vector<int>(p.length(),-1));

        return dfs(0,0,s,p, dp);
    }
    bool dfs(int i, int j, string s, string p, vector<vector<int>> &dp){
        
        if(j==p.length()){
            return i==s.length();
        }
        if(dp[i][j]>=0)
            return dp[i][j];
        
              bool first_match=(i<s.length() && (s[i]==p[j] || p[j]=='.' ));
        bool ans=0;

        if(j+1<p.length() && p[j+1]=='*')
            ans =  dfs(i, j+2, s, p, dp)||first_match && dfs(i+1, j, s, p, dp);
        
         else
            ans =  first_match && dfs(i+1,j+1,s,p, dp);
        
 dp[i][j]=ans;
    return ans;
        
    }
};