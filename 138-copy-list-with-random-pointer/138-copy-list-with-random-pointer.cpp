/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* curr = head;
        unordered_map<Node*, Node*>copy;
        copy[NULL] = NULL;
        
        while (curr){

            copy[curr] = new Node(curr->val);
            curr=curr->next;
        }
        curr = head;
        while(curr){
            copy[curr]->next = copy[curr->next];
            copy[curr]->random = copy[curr->random];
            curr=curr->next;  
        }
        return copy[head];
    }
};