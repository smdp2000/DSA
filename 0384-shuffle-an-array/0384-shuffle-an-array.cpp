class Solution {
    vector<int>original;
    
public:
    Solution(vector<int>& nums) {
        
        original = nums;
        
    }
    
    vector<int> reset() {
        
        return original;
        
    }
    
    vector<int> shuffle() {
        
        int last = original.size();
        vector<int>shuf = original;
        
        
        for(int i = original.size()-1;i>=0;i--){
            int j = rand()%last;
            swap(shuf[i],shuf[j]);
            last--;
        }
        return shuf;
        }
        
        
        
        
        
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */