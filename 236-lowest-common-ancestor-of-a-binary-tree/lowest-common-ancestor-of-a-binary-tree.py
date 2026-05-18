# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def f(node):
            if node is None or node==p or node==q:
                return node
            
            node1=f(node.left)
            node2=f(node.right)

            if node1 and node2:
                return node
                
            return node1 if node1 else node2

        return f(root)