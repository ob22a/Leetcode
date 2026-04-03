"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        
        # Map the nodes to correct index 
        nodeIdx = dict()
        node = head
        idx = 0

        while node:
            nodeIdx[node]=idx
            idx+=1
            node=node.next


        newHead = Node(head.val)
        cur = newHead
        original = head.next

        newNodeIdx = dict()
        newNodeIdx[0] = newHead
        idx=1
        
        while original:
            newNode = Node(original.val)
            newNodeIdx[idx]=newNode

            cur.next = newNode
            cur = cur.next
            original=original.next
            idx+=1
        
        node = newHead
        cur = head
        while cur:
            if cur.random:
                idx = nodeIdx[cur.random]
                newRandNode = newNodeIdx[idx]
                node.random = newRandNode
            
            node=node.next
            cur = cur.next


        return newHead