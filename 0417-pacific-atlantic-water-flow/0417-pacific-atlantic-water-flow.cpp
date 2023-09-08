class Solution {
public:
    bool isinAns(vector<vector<int>>&ans, int r, int c){
        for(int i=0; i<ans.size(); i++){
                if(ans[i][0]==r && ans[i][1]==c)
                    return true;
            }
        return false;
        }
    
    
    bool check(int r, int c, vector<vector<int>>&heights,vector<vector<int>>&ans){
        
      queue<pair<int,int>>q;
        bool atl = false;
        bool pac = false;
        q.push({r,c});

        set<tuple<int,int>>vis;
        vector<vector<int>>moves = {{0,1},{0,-1},{-1,0},{1,0}};
                                //vis.insert(make_tuple(r,c));

        while(!q.empty()){
            
            pair<int,int>cur = q.front();
            q.pop();
            
            int r = cur.first;
            int c = cur.second;
            if(isinAns(ans, r, c)){
                return true;
            }
            
            if(r==heights.size()-1 || c == heights[0].size()-1)
                atl=true;
            
            if(r==0 || c==0)
                pac = true;
            
            if(pac && atl)
                return true;
            
            for(int i=0; i<4; i++){
                
                int nr = r + moves[i][0];
                int nc = c + moves[i][1];
                
                if(nr>=0 && nr < heights.size() && nc>=0 && nc<heights[0].size() && vis.count(make_tuple(nr,nc))==0 && heights[nr][nc] <= heights[r][c]){
                q.push({nr,nc});
                vis.insert(make_tuple(nr,nc));
                }       
            }

        }
        
        return false;
}
    

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        bool pac,atl;
        vector<vector<int>>ans;
        
        
        for(int i=0; i<heights.size();i++){
            for(int j=0; j<heights[0].size(); j++){  
                if(check(i,j, heights, ans)){
                    ans.push_back({i,j});
                }
                    
            }
        }
        
        return ans;
    }
};