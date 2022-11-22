class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int ans=0;
        int r=height.size()-1;
        int maxL=height[0];
        int maxR=height[r];
        while(l<r){
            if(maxL>maxR){
                int trap =maxR-height[r];
                if(trap>=0)
                    ans+=trap;
                
                r--;
                maxR =max(maxR, height[r]);
                    
            }
            else{
                int trap =maxL-height[l];
                if(trap>=0)
                    ans+=trap;
                
                l++;
                maxL=max(height[l],maxL);
                    
            }
            
        }
        
        return ans;
            
        
    }
};