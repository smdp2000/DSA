class RandomizedSet {
    vector<int>st;
    unordered_map<int,int> mp;

public:
    RandomizedSet() {
        
        
        
    }
    
    bool insert(int val) {
        
        if(mp.find(val)!=mp.end())
            return false;
        
        st.push_back(val);
        mp[val] = st.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        
        if(mp.find(val)==mp.end())
            return false;
        
        int last = st.back();
        st[mp[val]] = last;
        mp[last] = mp[val];
        st.pop_back();
        mp.erase(val);
        
        return true;
        
        
    }
    
    int getRandom() {
        // random in a range, use rand() t get 0 to int_max shrink it by taking mod by size so range become 0 - size-1
        
        return st[rand()%st.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */