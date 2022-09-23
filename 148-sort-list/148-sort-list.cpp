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
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(left!=NULL && right!=NULL){
            if(left->val<right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else{
                curr->next = right;
                right = right->next;
           }  
          curr = curr->next;  
        }
        if(left!=NULL){
            curr->next = left;
            left = left->next;
        }
        if(right!=NULL){
            curr->next = right;
            right = right->next;
        }
        
        return head->next;
    }
    
    ListNode* sortList(ListNode* head) {
         if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode* left = head;
        ListNode* right = head->next;
                ListNode* temp = NULL;

        
        while(right && right->next){
            temp = left;
            left = left->next;
            right = right->next->next;
            
        }
        
        //right = left->next;
        //temp->next = NULL;
        //4213
        //left = 1;
         ListNode* tempy = NULL;

        tempy = left->next;
        left->next = NULL;
        //right = left;
        //left = NULL;
        
        
        return merge (sortList(head), sortList(tempy));
        
    }
};