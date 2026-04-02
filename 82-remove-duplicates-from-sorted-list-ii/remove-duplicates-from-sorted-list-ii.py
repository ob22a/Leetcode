# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1)
        cur = dummy

        n = head

        while n:
            if n.next and n.val==n.next.val:
                cur.next = None
                while n.next and n.val==n.next.val:
                    n=n.next
                if n:
                    n=n.next
                continue

            cur.next = n
            cur = cur.next
            n=n.next
        
        return dummy.next