class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<int,int>last;
        vector<int>output;
        
        for(int i=0; i<s.length();i++){
          last[s[i]]=i;
        }
        
        
        int end=0, size=0;
        
        for(int i=0; i<s.length(); i++){
            size+=1;
            
            end = max(end, last[s[i]]);
            
            if(i==end){
                output.push_back(size);
                size=0;
            }
        }
        
        return output;

    }
};