class Solution {
public:
    int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
    int subarrayLCM(vector<int>& nums, int K) {
        int l=0;
        int r=0;
        int minl = 1e8;
        int count=0;
        

        
        
        for(int i=0; i<nums.size(); i++){

            for(int j=i,lcm = 1; j<nums.size()&& K% nums[j] == 0; j++){
                        lcm = (nums[j]*lcm)/gcd(nums[j],lcm);
                        if(lcm==K)
                            count++;

                }

            }
        
        
        return count;
        
    }
};