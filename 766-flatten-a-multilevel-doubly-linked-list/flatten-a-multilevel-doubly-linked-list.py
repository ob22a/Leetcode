"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        stk = []
        cur = head
        prev = None

        while cur or stk:
            if not cur:
                cur=stk.pop()
                continue

            cur.prev=prev
            if prev: prev.next = cur
            prev = cur

            if cur.child:
                if cur.next: stk.append(cur.next)
                child = cur.child
                cur.child = None
                cur = child
                
            else:
                cur=cur.next
        
        # After building the flattened list, verify prev pointers
        curr = head
        while curr and curr.next:
            if curr.next.prev != curr or curr.child:
                print(f"Break at {curr.val} -> {curr.next.val}")
                break
            curr = curr.next

        return head

            
            