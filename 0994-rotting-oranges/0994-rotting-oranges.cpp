class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        
        int tf = 0;
int vis[n][m];
        for(int i = 0; i < n; i++) {
    fill(vis[i], vis[i] + m, 0);
}

         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                } else if(grid[i][j] == 1) {
                    vis[i][j]=1;
                }
            }
        }
        
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tf = max(tf,t);
            
            for(int i=0; i<4; i++){
                int nr = dr[i]+r;
                int nc = dc[i]+c;
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==1){
                    q.push({{nr,nc},1+t});
                    vis[nr][nc]=2;
                }
            }
            
        }
        
       for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }
        return tf;
        
    }
};