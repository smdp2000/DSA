class Solution {
public:
    
    bool dfs(int c, unordered_map<int, vector<int>>&adj, set<int>&visited){
        
        if(visited.count(c)!=0)
            return false;
        
        
           if(adj[c].empty())
            return true;
        
        visited.insert(c);
        
     
        
                for(auto ng : adj[c]){
                    
                    if(!dfs(ng, adj, visited))
                            return false;
                }
            
        adj[c].clear();
        
        visited.erase(c);
        
        return true;
        
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>>adj;
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        set<int>visited;
        
        for(int i=0; i<numCourses; i++){
            
            if(!dfs(i, adj, visited)){
                return false;
            }

        }
        
        return true;
        
    }
};