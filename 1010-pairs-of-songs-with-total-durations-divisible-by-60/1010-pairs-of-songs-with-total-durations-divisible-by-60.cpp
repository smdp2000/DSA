class Solution {
public:
    
    int numPairsDivisibleBy60(vector<int>& time) {
       
        int count=0;
        unordered_map<int, int>other;
        vector<int>help;
        
        for(int i=0; i<time.size(); i++){
              if(time[i]%60==0)
                  count+=other[time[i]%60]; //FOR REMAINDER EQUAL TO U HAVE TO SEARCH DIFFERENTLY
              else
                  count+=other[60-(time[i]%60)]; // FINDING REMAINDER
              other[time[i]%60]+=1; // SAVING REMAINDER
              
        }
        
        return count;
    }
};
/*
x=30
60-30%30
30:1

20:1
60-20 = 40:0

30:2

60-30 = 

40:1
50:1


*/