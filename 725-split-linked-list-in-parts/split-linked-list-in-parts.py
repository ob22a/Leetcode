# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        length = 0
        cur = head

        while cur:
            cur=cur.next
            length+=1
        
        cur = head
        sol = []

        while cur or k:
            if not cur:
                sol.append(None)
                k-=1
                continue
            
            start = cur
            moves = length//k
            if length%k!=0: moves+=1

            for _ in range(moves-1):
                if not cur or not cur.next:
                    break
                cur=cur.next
            
            length-=moves
            k-=1

            nextNode = cur.next
            cur.next = None
            sol.append(start)
            cur=nextNode
        
        return sol