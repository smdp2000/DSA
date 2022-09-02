class Solution {
    vector<int>root;
    vector<int> rank;
    int count;

public:
    
    int find(int x) {
    if (x == root[x]) {
        return x;
    }
    return root[x] = find(root[x]);
}
    void unionSet(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        
        if (rootx!=rooty){
            if(rank[rootx]>rank[rooty]){
                root[rooty] = rootx;}
            else if(rank[rooty]>rank[rootx]){
                root[rootx] = rooty;}
            else{
                root[rooty] = rootx;
                rank[rootx]+=1;
            }
            
            count--;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        root.resize(isConnected.size());
        rank.resize(isConnected.size());
        
         for (int i = 0; i < isConnected.size(); i++) {
            root[i] = i;
            rank[i] = 1;
        }
        int n = isConnected.size();
        int m = isConnected.size();
        count =n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j] && i!=j)
                    unionSet(i,j);    
            }
        }
        /*
         unordered_set<int> s;
         int count = 0;
        for (int i=0; i<root.size(); i++)
        {
       
        if (!s.count(root[i])) {
            s.insert(root[i]);
            count++;
        }
    }*/
                
        return count;
    }
};