class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>>pq;
        
        unordered_map<int, int>mp;
    
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]+=1;
            cout<< mp[nums[i]];
        }
               
        for(auto [a,b] : mp){
            
            pq.push({b,a});
        }
        
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
                
        }
        
        return res;
    }
};