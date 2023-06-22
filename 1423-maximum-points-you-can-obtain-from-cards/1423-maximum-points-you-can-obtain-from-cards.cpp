class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int maxy = accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int cursum = accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        
        for(int i=k-1; i>=0; i--){
            
            cursum = cursum - cardPoints[i]+cardPoints[cardPoints.size()-k+i];
                        

            
            maxy = max(maxy,cursum);
            
        }
        
        return maxy;
        
    }
};

