class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        vector<int>ind;
        int n = matrix[0].size()-1;
        cout<<n<<endl;
        
        for(int i=0; i<matrix.size();i++){
            
            if(matrix[i][0] == target || target==matrix[i][n])
                return true;
            
            if(matrix[i][0]<= target && target<=matrix[i][n])
               ind.push_back(i);
            
        
        }
        
         for(auto item: ind){
            for(int j=0; j<n; j++){
                cout<<matrix[item][j];
                if(matrix[item][j]==target)
                    return true;
                
                
            }
                
    }
        
        return false;
        
    }
};