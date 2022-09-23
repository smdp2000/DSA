/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:

ListNode* merge(ListNode* l1 , ListNode* l2)
{
    ListNode* head = NULL;
    
    if(l1==NULL)
    {
        return(l2);
    }
    if(l2==NULL)
    {
        return(l1);
    }
    
    if(l1->val <= l2->val)
    {
        head = l1;
        head->next = merge( l1->next , l2 );
    }
    else
    {
        head = l2;
        head->next = merge(l1 , l2->next);
    }
    return(head);
}


ListNode* sort(ListNode*  head, ListNode* tail)
{
    if(head == tail) return head;
    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast!=tail && fast->next!=tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
            
    fast = slow->next;
    slow->next = NULL;
    
    return( merge( sort(head,slow) , sort(fast , tail)));
    
    
}

ListNode* sortList(ListNode* head) {

    if(!head) return head;

    
    ListNode* tail = head;
    while(tail->next)
    {
        tail = tail->next;
    }

    return( sort(head , tail));
}
};