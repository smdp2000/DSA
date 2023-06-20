class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j;
        while(i<nums.size()){
            j=i+1;
            while(nums[i]==0 && j<nums.size()){
                nums[i]=nums[j];
                nums[j]=0;
                j++;
            }
            i++;
        }
    }
};