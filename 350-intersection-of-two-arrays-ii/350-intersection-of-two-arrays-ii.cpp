class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
        vector<int>ans;
        for(int i=0; i<nums1.size(); i++){
            
            if(map.find(nums1[i])!=map.end())
                    map[nums1[i]]+=1;
            else
                    map[nums1[i]] = 1;
        }
        
        for(int j=0; j<nums2.size();j++){
            if(map[nums2[j]]>0){
                ans.push_back(nums2[j]);
                map[nums2[j]]--;
            }
        }
        
        return ans;
    }
};