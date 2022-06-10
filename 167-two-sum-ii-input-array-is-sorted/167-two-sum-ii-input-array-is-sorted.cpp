class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>sol(2);
        int i=0;
        int j= numbers.size()-1;
        
        while(i<j){
            
            if(numbers[i] + numbers[j] > target)
                j--;
            else if(numbers[i] + numbers[j] <target)
                i++;
            else
                return {i+1, j+1} ;
            
        }
        return {-1};
    }
};