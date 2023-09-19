class Node{
    public:
    int key, val;
    
    Node* prev = NULL;
    Node* next = NULL;
    
    Node(int k, int v){
        key = k;
        val = v;
        
    }
};

class LRUCache {
public:
    
    Node* left;
    Node* right;
    int cap;
    
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    void remove(Node* node){
        
        Node* previ = node->prev;
        Node* nexti = node->next;
        previ->next = nexti;
        nexti->prev = previ;
        
    }
    
    void insert(Node* node){
        
        Node* previ, *nexti;
        previ = right->prev;
        nexti = right;
        node->prev = previ;
        previ->next = node;
        node->next = nexti;
        right->prev = node;
    }
    
    int get(int key) {
        if(mp.count(key)>0){
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    void put(int key, int value) {
        if(mp.count(key)>0){
            remove(mp[key]);}
        mp[key] = new Node(key, value);
        insert(mp[key]);
    
        if(mp.size()>cap){
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->key);
            
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */