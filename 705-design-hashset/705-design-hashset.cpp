class MyHashSet {
public:
    vector<vector<int>>mp;
    int siz;
    MyHashSet() {
        siz = 100;
        mp.resize(100);
        
        
    }
    int hash(int key){
        
        return key%siz;
    }
    
    void add(int key) {
        if(contains(key)) return;
        
        mp[hash(key)].push_back(key);
        
        
        
        
        
    }
    
    void remove(int key) {
        
        for(auto i = mp[hash(key)].begin(); i != mp[hash(key)].end(); ++i)
            if(*i==key)
            {
                mp[hash(key)].erase(i);
                break;
            }
                
                
        
    }
    
    bool contains(int key) {
        return find(mp[hash(key)].begin(), mp[hash(key)].end(), key)!= mp[hash(key)].end();
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */