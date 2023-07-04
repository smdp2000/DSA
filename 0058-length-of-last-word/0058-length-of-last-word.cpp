class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans="";
        for(int i=s.size()-1; i>=0; i--){
            
            
            if(s[i]== ' ' && ans.size())
                break;
                
            else
                if(s[i]!=' ')
                    ans = s[i] + ans;
            
        }
        
       // cout<<ans;
        return ans.size();
        
    }
};