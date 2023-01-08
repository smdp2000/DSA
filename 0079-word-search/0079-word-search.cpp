class Solution {
public:
    
    bool search(int i, int j, int ch, vector<vector<char>>&board, string word){
        
       if(ch==word.size()){
           return true;
       }
        
        if(i<0 || i>=board.size() || j>=board[0].size() || j<0 || board[i][j] == '.'|| board[i][j]!=word[ch])
            return false;
            
        board[i][j]='.';
            
        bool chk = search(i, j+1,ch+1,board, word)||search(i,j-1,ch+1,board,word)||search(i+1,j,ch+1,board,word)||search(i-1,j,ch+1,board,word);
        
        board[i][j]=word[ch];
        
        return chk;
            
        
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(search(i,j,0,board,word))
                        return true;
            }
                
        }
        return false;
    }
};