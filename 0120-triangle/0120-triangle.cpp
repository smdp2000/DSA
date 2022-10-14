class Solution {
public:
    
    int getcost(int i, int j, int m, vector<vector<int>>&a, vector<vector<int>>&dp){
        
        if(i==m-1)
            return a[m-1][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int d= a[i][j]+getcost(i+1,j,m,a,dp);
        int di= a[i][j]+getcost(i+1,j+1,m,a,dp);
        return dp[i][j] = min(d,di);
}
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        
        vector<vector<int>>dp(m, vector<int>(m,-1));
        return getcost(0,0,m,triangle, dp);
        
    }
};