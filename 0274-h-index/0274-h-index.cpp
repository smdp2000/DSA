class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        vector<int>count(n+1,0);
        
        for(int i=0; i<n; i++){
            
            if(citations[i]>n){
                count[n]+=1;
            }
            else{
                count[citations[i]]+=1;
            }
            
        }
        
        int papers=0;
        //[1,1,0,1,0,2]
        //[5,4,3,3,2,2]
        for(int i=n; i>=0; i--){
            papers+=count[i];
            
            if(papers>=i)
                return i;
        }
        
        return n;
    }
};