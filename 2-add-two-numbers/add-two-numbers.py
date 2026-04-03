# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1)
        cur = dummy

        p1 = l1
        p2 = l2
        carry = 0

        while p1 or p2:
            total = carry
            
            if p1:
                total+=p1.val

            if p2:
                total+=p2.val

            carry = 1 if total>9 else 0
            
            val = total%10
            newNode = ListNode(val)
            cur.next = newNode

            if p1: p1=p1.next
            if p2: p2=p2.next
            cur = cur.next
        
        if carry:
            cur.next=ListNode(1)
        
        return dummy.next