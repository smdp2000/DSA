class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int ri,coli;
        vector<pair<int,int>>ind;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    ind.push_back(make_pair(i,j));
                    cout<<i<<" "<<j;
                }
            }
        }
        
            
        for(int i=0; i<ind.size();i++){
                ri=ind[i].first;
            for(int j=0; j<matrix[0].size(); j++)
                    matrix[ri][j]=0;
        }
        for(int j=0; j<ind.size(); j++){
                coli = ind[j].second;
                cout<<coli;
        for(int i=0; i<matrix.size(); i++){
                matrix[i][coli]=0;
        }
    }
        
        
        
        
    }
};