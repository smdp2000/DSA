class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(haystack==needle)
            return 0;
        
         if(needle.size()==0)
         return 0;
        if(haystack.size()<needle.size())
          return -1;  
        int n= needle.length();
        
        for(int i=0; i<=haystack.length()-n; i++){
            cout<<haystack.substr(i,n);
            if(haystack.substr(i,n)==needle)
                return i;
        }
            return -1;

    }
    
};