class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.length()-1;
        int m=0;
        
        while(m<n){
            if(!isalnum(s[m])) m++;
            else if(!isalnum(s[n])) n--;
            else{
                if(tolower(s[m++])!=tolower(s[n--])) return false;
            }
                
        }
        
        return true;
        
    }
};