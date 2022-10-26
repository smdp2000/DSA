class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        
        Node(int key, int val){
            
            this->val = val;
            this->key = key;
            
        }
        
    };
    
    unordered_map<int, Node*>mp;
    Node* head=new Node(-1,-1);;
    Node* tail=new Node(-1,-1);;
    int capacity;
    
    LRUCache(int capacity) {
        
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    
    void removeNode(Node* curNode){
       
        Node* prevNode = curNode->prev;
        Node* nextNode = curNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
    }
    
    void addNode(Node* curNode){
        
        curNode->next = head->next;
        curNode->prev = head;
        curNode->next->prev = curNode;
        head->next = curNode;
        
    }
    
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end())
        {
            Node* curnode = mp[key];
            int result = curnode->val;
            mp.erase(key);
            removeNode(curnode);
            addNode(curnode);
            mp[key]=head->next;
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* curnode = mp[key];
            mp.erase(key);
            removeNode(curnode);
            
        }
        
        if(mp.size()==capacity){
            mp.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        
        addNode(new Node(key, value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */