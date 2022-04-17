class Solution {
public:
    int firstUniqChar(string s) {
        
        int freq[26] = {0};
        
        for(int i=0; i<s.length(); i++){
            int ind = s[i] - 'a';
            freq[ind]++;
            
        }
        
        for(int i=0; i<s.length(); i++){
            if(freq[s[i] - 'a']==1)
                return i;
        }
        
        
        return -1;
        
    }
};