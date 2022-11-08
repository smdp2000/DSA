class Solution {
public:
    void reversal(vector<int>&nums, int i, int j){
        
        while(i<j){
            int temp = nums[j];
            nums[j]=nums[i];
            nums[i]=temp;
            i++;
            j--;
        }
        
    }
    vector<int>& rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k < 0){ 
            k += nums.size();
        }
        int n=nums.size();
        if(n==1)
            return nums;
        reversal(nums, 0, n-k-1);
        reversal(nums, n-k, n-1);
        reversal(nums, 0, n-1);
        
        return nums;
    }
};