# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        while cur:
            node = cur
            while cur and node.val==cur.val:
                cur=cur.next
            if node!=cur:
                node.next=cur

        return head
            