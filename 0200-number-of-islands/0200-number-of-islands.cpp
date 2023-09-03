class Solution {
public:
    
    bool findIsland(vector<vector<char>>& grid,int r, int c, set<pair<int,int>>&visited){
        
        if(r>=grid.size() || r<0 || c>=grid[0].size() || c<0){
            return false;
        }
        
        if(grid[r][c]=='0')
            return false;
        if(visited.count({r,c})!=0)
            return false;
        
        visited.insert({r,c});
        
        findIsland(grid, r+1,c,visited);
        findIsland(grid, r,c+1,visited);
        findIsland(grid, r-1,c,visited);
        findIsland(grid, r,c-1,visited);

        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        set<pair<int,int>>visited;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                  if(findIsland(grid,i,j, visited)==true){
                    count++;
            }    
        }
    }
        return count;
    }
};