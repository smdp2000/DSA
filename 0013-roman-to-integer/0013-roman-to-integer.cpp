class Solution {
public:
    int romanToInt(string s) {
        // if smaller value before the bigger that mean subtract else add;
        unordered_map<char,int>mp;
        mp['I'] = 1;
        mp['V']=5;
        mp['X']= 10;
        mp['L']=50;
        mp['C']=100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int val=0;
        int n=s.size();
        for(int i=0; i<s.length();i++){
            if(i+1<n && mp[s[i]]<mp[s[i+1]])
                val-= mp[s[i]];
            else
                val+=mp[s[i]];
            
        }
        
        return val;
    }
};