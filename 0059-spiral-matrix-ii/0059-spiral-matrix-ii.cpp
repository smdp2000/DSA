class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>matrix(n, vector<int>(n,0));
       
          int l = 0, r = matrix[0].size(), t = 0, b = matrix.size();
        vector<int>res;
        for(int i=0; i<n*n; i++){
            res.push_back((i+1));
        }
        
        int k=0;
        
        while(l<r && t < b)

        {
            for(int i=l; i<r; i++){
                matrix[t][i] = res[k++];
                cout<<t<<" "<<i<<endl;
                cout<<"A"<<endl;
                
            }
            
            t++;
            
            for(int i=t; i<b;i++){
                matrix[i][r-1] = res[k++];
                                              cout<<"A3"<<endl;


            }
            
            r--;
            
            if (!(l < r && t < b)) // imp condition
                break;
            
            for(int i=r-1; i>=l; i--){
                matrix[b-1][i]=res[k++];
                                cout<<"A1"<<endl;

                  
            }
            
            b--;
            
            for(int i=b-1; i>=t; i--){
                matrix[i][l] = res[k++];
                                cout<<"A2"<<endl;

                
            }

            l++;
            
        }
        
        return matrix;
        
    
                
            
    }
};