class Solution {
public:
    bool checkValidString(string s) {
        int lmin=0, lmax=0;
        
        int i=0;
        
        while(i<s.length()){
            
            if(s[i]=='('){
                
                lmax++;
                lmin++;
                
}
                
            if(s[i]==')')
            {
                lmax--;
                lmin--;
            }
            
            if(s[i]=='*'){
                lmin--;
                lmax++;
            }
            
            if(lmax<0)
                return false;
            
            if(lmin<0)
                lmin=0;
            
         i++;   
        }
        
        if(lmin==0)
            return true;
        
        return false;
    }
};