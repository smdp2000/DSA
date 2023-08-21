class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        priority_queue<int>pq1;
                priority_queue<int>pq2;
                priority_queue<int>pq3;
        
        for(int i=0; i<triplets.size(); i++){
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
                
            
            pq1.push(triplets[i][0]);
            pq2.push(triplets[i][1]);
            pq3.push(triplets[i][2]);
            
            }
        }
// cout<<pq1.top()<<endl;
// cout<<pq2.top()<<endl;
// cout<<pq3.top()<<endl;
        if(pq1.empty()|| pq2.empty()||pq3.empty())
            return false;

        if(pq1.top()!=target[0] || pq2.top()!=target[1] || pq3.top()!=target[2])
            return false;
        
        return true;
        
    }
};