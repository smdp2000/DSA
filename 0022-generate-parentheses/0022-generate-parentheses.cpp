class Solution {
public:
    
    void dfs(vector<string>&ans, string s, int start, int end, int n){
        if(s.size()==2*n)
            ans.push_back(s);
        
        if(start<n)
            dfs(ans,s+'(',start+1,end,n);
        if(end<start)
            dfs(ans,s+')',start, end+1,n);
            
            
            
        }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        string s;
        
        dfs(ans,"",0,0,n);
        
        return ans;
        
        
        
    }
};