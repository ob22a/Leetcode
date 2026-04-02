# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right:
            return head

        dummy = ListNode(-1,head)
        leftNode = dummy
        for _ in range(left-1):
            leftNode=leftNode.next
        
        rightNode = dummy
        for _ in range(right):
            rightNode=rightNode.next
        
        startNode = leftNode
        endNode = rightNode.next
        startReversedNode = leftNode.next

        # Detact the linked list
        startNode.next = None
        rightNode.next = None

        def reversedLinkedList(head):
            prev = None
            cur = head
            while cur:
                nextNode = cur.next
                cur.next = prev
                prev = cur
                cur = nextNode
        
            return prev
        
        # Attach the reversed list again
        startNode.next = reversedLinkedList(startReversedNode)
        cur = startNode.next

        while cur and cur.next:
            cur=cur.next
        
        cur.next = endNode

        return dummy.next