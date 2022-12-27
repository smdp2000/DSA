class Solution {
public:
    
    string createkey(string str){
        vector<int>freq(26);
        for(int i=0; i<str.length(); i++){
            
            freq[str[i]-'a']++;
            
        }
        string key = "";
        for(int j=0; j<26; j++){
            key.append(to_string(freq[j] + 'a'));
        }
        
        return key;
        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
            unordered_map<string,vector<string>>m;
        
        for(int i=0; i<strs.size();i++){
            
            string key = createkey(strs[i]);
            
            m[key].push_back(strs[i]);
            
            
        }
        
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
        
    }
    
    
    
};