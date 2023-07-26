class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int, vector<int>, greater<int>>lg;
        
        
        
        for(int i=0; i<k; i++)
        {
            lg.push(nums[i]);
        }
        
        
        for(int i=k; i<nums.size(); i++)
        {
            if(lg.top()<nums[i]){
                lg.pop();
                lg.push(nums[i]);
            }
        }
        
        return lg.top();
    }
};