/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        if(head==NULL)
            return false;
    if(head->next!=NULL && head->next->next!=NULL){
        slow = head;
        fast = head;
    }
        else
            return false;
        
        while(fast!= NULL && fast->next!=NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        
        return false;
        
    }
};