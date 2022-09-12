class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
                    priority_queue<pair<double, vector<int>>>lg;
        vector<vector<int>>res;
        for(int i=0; i<points.size(); i++)
        {
            double dis = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            lg.push({dis, points[i]});
            if(lg.size()>k)
                lg.pop();
        }
        while(!lg.empty())
        {
            res.push_back(lg.top().second);
            lg.pop();
            
        }
        
        return res;
        
    }
};