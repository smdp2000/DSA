class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxl=0,maxr=0;
        int li=0,ri=0;
        int cura=0;
        while(l<r){
            
            cura = max(cura, min(height[l],height[r])*(r-l));
            
            if(height[l]<height[r]){
                l++;
            }
             else{
                 r--;
             }
            
            
        }
        
        return cura;
        
        
        
        
    }
};