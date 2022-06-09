class Solution {
public:
    vector<vector<string> > sols;
    bool safe(vector<string>&Q, int row, int col){
        
        for(int i=col; i>=0; i--){
            if(Q[row][i] == 'Q')
                return false;
        }
        int i,j;
        for(i=row,j= col; i>=0 && j>=0 ; i--,j--){
            if(Q[i][j]=='Q')
                return false;
        }
         
        for(i=row,j= col; i<Q.size() && j>=0 ; i++,j--){
            if(Q[i][j]=='Q')
                return false;
        }
        
        return true;
    }
    
    void findQsol(vector<string>&Q, int col){
        if(col==Q[0].size()){
            sols.push_back(Q);
            return ;
        }
            
        for(int row=0; row<Q.size(); row++){
            if(safe(Q, row, col)){
                
            
                Q[row][col] = 'Q';
                
                findQsol(Q, col+1);
                    //return true;
                
                Q[row][col]='.';
                  
            }
            
            
            
        }
        
       // return false;
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
    vector<string>Q(n, string(n,'.'));
        
    
    findQsol(Q, 0);
       
        
    return sols;
        
    }
};