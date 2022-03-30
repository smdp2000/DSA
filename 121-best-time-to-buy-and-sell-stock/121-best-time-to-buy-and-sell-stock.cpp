class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int lsf = INT_MAX;
        int cf = 0;
        int of = 0;
        
      for(int i=0; i<prices.size(); i++){
          
            if(prices[i]<lsf){
                lsf = prices[i];
            }
          
          cf = prices[i] - lsf;
          of = max(cf, of);
      }
        
        return of;
        
    }
};