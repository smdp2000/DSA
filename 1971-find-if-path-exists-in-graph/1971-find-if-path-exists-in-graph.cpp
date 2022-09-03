class Solution {
public:
    bool dfs(vector<int>adj[], int s, int d, vector<bool>& vis){
        
        vis[s] = true;
        
        if(s==d)
            return true;
        
        for(int x : adj[s]){
            if(vis[x]!=true){
                if(dfs(adj, x, d, vis))
                    return true;
                
            }       

            }
            return false;
        }
    
    void make(vector<int>adj[], vector<vector<int>>& edges){
       // for(int i:adj)
        for(vector<int>x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);  
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //int s,d;
        vector<int>adj[n];
        make(adj, edges);
        vector<bool> vis(n,false);  
        bool res  = dfs(adj, source, destination, vis);
        return res;
    }
};