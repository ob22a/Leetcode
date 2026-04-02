# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        left = right = head
        n = 0
        
        cur = head
        prev = None
        while cur:
            n+=1
            prev = cur
            cur=cur.next
        
        if n==0:
            return head

        k = k%n

        if k==0:
            return head

        for _ in range(k):
            right=right.next

        while right and right.next:
            left=left.next
            right=right.next
        
        rotatedNode = left.next
        left.next = None
        prev.next = head

        return rotatedNode