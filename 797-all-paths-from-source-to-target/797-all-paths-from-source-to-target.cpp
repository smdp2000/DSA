class Solution {
public:
    vector<vector<int>>results;
    int t;
    void backtrack(int cur, vector<int>&path, vector<vector<int>>& graph){
        if(cur==t){
            results.push_back(vector(path));
            return;
        }
        
        for(int x : graph[cur]){
            path.push_back(x);
            backtrack(x, path, graph);
            path.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path{0};
        t = graph.size()-1;
        backtrack(0, path, graph);
        return results;
    }
};