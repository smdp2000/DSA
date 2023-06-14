class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
       int start=0;
       long long sum=0;
        int ans=0;
        deque<int>dq;
        
        for(int end=0; end<chargeTimes.size(); end++){
            
            sum+=runningCosts[end];
            while(!dq.empty()&& chargeTimes[dq.back()]<=chargeTimes[end]) dq.pop_back();
            
            dq.push_back(end);
            cout<<dq.size()<<endl;
            
            long long current_cost = chargeTimes[dq.front()]+ (end-start+1) * sum;
            
            while(current_cost>budget){
                
                sum-=runningCosts[start];
                cout<<dq.front();
                if(dq.front()==start) dq.pop_front();
                                cout<<dq.front();

                
                start++;
                if(start>end){
                    current_cost=0;
                }
                else{
                                    current_cost = chargeTimes[dq.front()] + (end-start+1) * sum;

                }
                
                
            }
            
            ans=max(ans, end-start+1);
            
            
        }
        
        return ans;
            
            
            
        }
};