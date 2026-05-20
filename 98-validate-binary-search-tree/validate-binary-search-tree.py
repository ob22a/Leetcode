# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def f(node,maxi,mini):
            if not node:
                return True
            
            if not (mini<node.val<maxi):
                return False
            
            return f(node.left,node.val,mini) and f(node.right,maxi,node.val)
        
        return f(root,float('inf'),-float('inf'))