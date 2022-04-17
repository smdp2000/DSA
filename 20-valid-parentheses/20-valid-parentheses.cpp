class Solution {
public:
    bool isValid(string s) {
        
        stack<int>bl;
        
        if(s.length()==1)
            return false;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                bl.push(s[i]);
        
        
        else{
            cout<<"here";
            if(bl.empty() || s[i]==')' && bl.top()!='('){
                    cout<<"1";
                    return false;
            }
            else if(bl.empty() || s[i]=='}'&& bl.top()!='{')
                    return false;
            else{
                if (bl.empty() || s[i]==']'&& bl.top()!='['){
                    cout<<"3";
                        return false;}
            }
            bl.pop();
        }
            
        }
    
        return bl.empty();
    }
};