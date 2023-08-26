bool cmp(vector<int>a, vector<int>b){
        if(a[0]<b[0]){
            return true;
        }
        
        return false;
    }
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>>ans;
        int i;
        for(i=0; i<intervals.size()-1; i++){
            if(intervals[i+1][0]>intervals[i][1]){
                ans.push_back(intervals[i]);
                
            }
            else{
                int start = intervals[i][0];
                int end = intervals[i][1];
                while(i+1<intervals.size() && end>=intervals[i+1][0]){
                    start=min(start, intervals[i+1][0]);
                    end = max(end, intervals[i+1][1]);
                    i++;
                }
                
                ans.push_back({start,end});
            }
            
        }
        if(i==intervals.size()-1){
            ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};