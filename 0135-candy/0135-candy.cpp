class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>ans(ratings.size(),1);
        
        int n = ratings.size();
        
//         if(n>1 && ratings[0]>ratings[1])
//             ans[0] = ans[1]++;
        
//         if(n>1 && ratings[n-1]>ratings[n-2])
//             ans[n-1] = ans[n-2]+1;
        
   //     if(n>2){
            
             
        for(int i=1; i<ratings.size(); i++){
            
            if(ratings[i]>ratings[i-1])
                ans[i] = ans[i-1]+1;
               
               
           
        }
        
        for(int i=0; i<ans.size(); i++)
                    cout<<ans[i]<<" ";
        
        cout<<endl;
        
        for(int i=ratings.size()-2; i>=0; i--){
            
             
         if(ratings[i] > ratings[i+1] && ans[i]<=ans[i+1])
                ans[i] = ans[i+1] +1;
               
           
        }
        
        
        
            
  //  }
        
                for(int i=0; i<ans.size(); i++)
                    cout<<ans[i]<<" ";

            
       
        return accumulate(ans.begin(), ans.end(), 0);
            
        
    }
};