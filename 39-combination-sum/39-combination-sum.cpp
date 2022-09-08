class Solution {
public:
    vector<vector<int>>results;
    void dfs(int i, vector<int>&combinations, int cursum, int target, vector<int>&candidates){
        if(cursum== target){
            results.push_back(combinations);
            return;}
        if (i>candidates.size()-1 || cursum>target )
            return;
        
        combinations.push_back(candidates[i]);
        dfs(i, combinations, cursum+candidates[i], target, candidates);
        combinations.pop_back();
        dfs(i+1, combinations, cursum, target, candidates);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>combinations;
        dfs(0, combinations, 0, target, candidates);
        return results;
    
            
        
        
    }
};