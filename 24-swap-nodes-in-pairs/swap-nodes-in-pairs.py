# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1,head)
        cur = dummy

        while cur and cur.next and cur.next.next:
            firstNode = cur.next
            secondNode = firstNode.next
            remainingNode = secondNode.next

            cur.next = secondNode
            secondNode.next = firstNode
            firstNode.next = remainingNode

            cur = firstNode

        return dummy.next