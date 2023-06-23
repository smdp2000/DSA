class Solution {
public:
    int partitionString(string s) {
        
        unordered_map<char, int>mp;
        int pt=1;
        
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end()){
                pt++;
                mp.clear();
                cout<<s[i]<<endl;
                mp[s[i]]=1;
            }
            else{
                mp[s[i]]=1;
            }
        }
        
        return pt;
    }
};