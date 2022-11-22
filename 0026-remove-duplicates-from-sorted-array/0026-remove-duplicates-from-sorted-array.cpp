class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size();
        }
        int prev=nums[0];
        int k=1;
        int j=1;
        int n= nums.size();
    for(int i=1; i<n; i++)    {
        if(nums[i]!=prev){
            
            prev= nums[i];
            nums[k++]=nums[i];
        }
    }   
        return k;
    }
};