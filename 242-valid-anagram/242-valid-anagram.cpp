class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int>mp, tp;
       // unordered_map<int, int> :: iterator it;
        if(s.length()!=t.length())
            return false;
        
        for(int i=0; i<s.length(); i++){
                        cout<<s[i]<<endl;

            if(mp.find(s[i])==mp.end())
                mp[s[i]]=1;
            else
                mp[s[i]]+=1;
            
           // cout<<mp[s[i]]<<endl;
            
            if(tp.find(t[i])==tp.end())
                tp[t[i]]=1;
            else
                tp[t[i]]+=1;
            
          //  cout<<"xxx"<<tp[t[i]]<<endl;

            
            
        }
      //  cout<<"size"<<mp.size();
        
        for(auto it=mp.begin(); it!=mp.end(); it++){
            //cout<<it->first<<" "<<it->second<<endl;
            if(tp[it->first]!=it->second)
               return false;
            }
        
        return true;
        
                
    }
};