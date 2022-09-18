class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    private:
    vector<int> root;
    vector<int> rank;
    
};

class Solution {


public:
    
        int getParent(vector<int>& parents, int idx){
        
        if(parents[idx]==idx){
            return idx;
        }
        
        parents[idx] = getParent(parents, parents[parents[idx]]);
        
        return parents[idx];
        
        
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
               
                 vector<int> parents(points.size());        
        iota(parents.begin(), parents.end(), 0);
                typedef pair<int, pair<int,int>> pi;
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        //priority_queue<pair<int, pair<int,int>>, vector<pi>greater<int> > pq;
        for(int i=0; i<points.size(); i++){
            vector<int>& cd1 = points[i];
            for(int j=i+1; j<points.size();  j++){
                vector<int>& cd2 = points[j];
                
                int cost = abs(cd1[0] - cd2[0]) +
                           abs(cd1[1] - cd2[1]);
                
                pq.push({cost,{i,j}});
                cout<<pq.top().first;
            }
        }
        int count = points.size()-1;
        int tcost = 0;
        while(count>0){
            
            pair<int, pair<int,int>> curr = pq.top();
            cout<<curr.first<<endl;
            pq.pop();
            int point1 = getParent(parents, curr.second.first);
            int point2 = getParent(parents, curr.second.second);
             
           
            if(point1!=point2){
                    //uf.unionSet(point1,point2);
                                parents[point1] = point2;

                    tcost+=curr.first;
                    count--;
            
            }
            
            
        }
        return tcost;
    }
};