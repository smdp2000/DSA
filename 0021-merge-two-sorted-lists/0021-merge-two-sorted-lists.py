# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        
        if(not list1):
            return list2
        if(not list2):
            return list1
    
        strt, end = (list1, list2) if list1.val<list2.val else (list2, list1)
    
        head = strt
    
        while(strt and end):
            while(strt.next and strt.next.val < end.val):
                strt = strt.next
        
            strt.next, end = end, strt.next
            strt = strt.next
        
        return head
            
            
        