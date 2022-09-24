class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
        int temp[n];
        int l=0;
        int r=0;
        int k=0;
        
        while(l<nums1.size() && r<nums2.size())
            if(nums1[l]<nums2[r])
                temp[k++] = nums1[l++];
            else
                temp[k++] = nums2[r++];
        
        while(l<nums1.size())
                temp[k++] = nums1[l++];
        
        while(r<nums2.size())
                temp[k++] = nums2[r++];
        cout<<temp[n/2];
        if (n%2 == 0)
            
            return double((temp[n/2] + temp[(n/2)-1] )/float(2));
        return double(temp[(n-1)/2]);
        
        
        
                
        
        
    }
};