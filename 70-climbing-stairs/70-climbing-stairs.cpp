class Solution {
public:
    int climbStairs(int n) {
        int a[45];
        a[0]=1; a[1]=2;
        for(int i=2; i<n; i++)
            a[i] = a[i-1] + a[i-2];
        //return (n-1) + (n-2);
        
        return a[n-1];
    }
};