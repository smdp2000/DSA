class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //vector<vector<int>>dp(m, vector<int>(n, 0));
        vector<int>prev(n,0);
        for(int i=0; i<m ; i++){
             vector<int>cur(n,0);
            for(int j=0; j<n; j++){
                if(i==0&&j==0) cur[j]=grid[i][j];
                else{
                int r=grid[i][j],b=grid[i][j];
                if (i>0) r +=prev[j];
                    else
                        r=INT_MAX;
                if(j>0) b +=cur[j-1];
                    else
                        b=INT_MAX;
                cur[j]= min(r, b);}
            }
                prev=cur;
            }
        
        return prev[n-1];
    }
};