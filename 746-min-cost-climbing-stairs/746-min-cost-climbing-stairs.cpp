class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int nc[1001];
        
        int n = cost.size();
        nc[0] = cost[0];
        nc[1] = cost[1];
        
        
        for(int i=2; i<cost.size(); i++)
            
            nc[i] = cost[i] + min(nc[i-1], nc[i-2]);
        
        return min(nc[n-1], nc[n-2]);
        
    }
};