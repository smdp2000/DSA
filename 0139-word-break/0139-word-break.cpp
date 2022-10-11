class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool>dp(s.length()+1); 
        dp[s.length()]=true;
        for(int i=s.length()-1; i>=0; i--){
            for(auto val : wordDict){
                cout<<val<<endl;
                cout<<val.length()<<endl;
                cout<<s.substr(i, val.length())<<endl;
                cout<<endl;

                if(i+val.length()<=s.length() and s.substr(i, val.length())== val)
                    dp[i] = dp[i+val.length()];
                if(dp[i])
                    break;
            }
    }
        return dp[0];
                    
        
    }
};