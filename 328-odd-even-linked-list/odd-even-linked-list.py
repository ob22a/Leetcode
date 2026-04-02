# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
            
        dummy1 = ListNode(-1,head)
        left = dummy1
        
        dummy2 = ListNode(-1,head)
        right = dummy2

        cur = head
        idx = 1

        while cur:
            if idx%2==1:
                left.next=cur
                left=left.next
            else:
                right.next=cur
                right=right.next
        
            idx+=1
            cur=cur.next
        
        left.next = dummy2.next
        right.next = None

        return dummy1.next