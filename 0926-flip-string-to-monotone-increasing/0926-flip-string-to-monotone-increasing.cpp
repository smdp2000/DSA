class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones=0, ans=0;
        for(int i=0; i<s.size(); i++){
            
            if(s[i]=='1')
                ones++;
            else{
                int flipones=ones; // decided to flip ones but not his zero;
                int flip_curzero=ans+1; //flip this zero so ans length increase by 1;
                ans= min(flipones,flip_curzero);
            }
        }
        
        return ans;
        
    }
};