
class Solution {
public:
    unordered_map<char, string> L = {{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    
    void dfs(int pos, int len, string digits, vector<string>&ans, string s){
        
        if(pos==len)
            ans.push_back(s);
        else{
        string letters = L[digits[pos]];
        
        for(int i=0; i<letters.size(); i++){
            dfs(pos+1, len, digits, ans, s+letters[i]);
        }
            
        }
        
    }

    vector<string> letterCombinations(string digits) {
       
        int len = digits.size();
        
        
        vector<string>ans;
        if (len==0)
                return ans;
        
        dfs(0, len, digits, ans, "");
        return ans;
        
    }
};