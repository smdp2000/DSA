class Solution {
public:
    
   
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
         unordered_set<string>mp(words.begin(),words.end());
        vector<string>res;
        for(int k=0; k<words.size(); k++){
            string s = words[k];
            int n= s.size();
            vector<int>dp(n+1);
            
            dp[0]=1;
            
            for(int i=0; i<s.size();i++ ){
            if(dp[i]!=1){
                continue;
            }
            for(int j=i+1; j<=n; j++){    
                if(j-i<n && mp.count(s.substr(i,j-i)))
                    dp[j]=1;  
            }
                
        

            if(dp[n]==1){
                res.push_back(s);
                break;
            }
                
            }
            
        }
        
        return res;
        
    }
};


