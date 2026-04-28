# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        sol=[]

        def f(node):
            if node:
                sol.append(node.val)
                f(node.left)
                f(node.right)
        f(root)
        
        return sol