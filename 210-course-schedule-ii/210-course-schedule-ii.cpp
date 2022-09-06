class Solution {
public:
    void makegraph(vector<int>adj[], vector<vector<int>>& prerequisites, vector<int>&indegree){
        
        for(vector<int>x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]+=1;
        }
        
    }
    vector<int> findOrder(int numcourses, vector<vector<int>>& prerequisites) {
       
        vector<int>adj[numcourses];
        vector<int>indegree(numcourses);
        makegraph(adj, prerequisites, indegree);
        vector<int>topo;
        queue<int>q;
            for (int i = 0; i < numcourses; i++){
                if(indegree[i]==0)
                    q.push(i);
            }
        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
           // topo.push_back(curr);
            for(auto j : adj[curr])
            {
                indegree[j]-=1;
                if(indegree[j]==0)
                    q.push(j);
            }
            topo.push_back(curr);
            count++;
        }
                 
        if(count!=numcourses)
            return {};
        return topo;
        
        
    }
};