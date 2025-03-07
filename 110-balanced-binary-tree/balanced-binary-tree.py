# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        isbalanced=[True]
        def height(root):
            if root is None:
                return 0

            left=height(root.left)
            right=height(root.right)
            
            if abs(left-right)>1:
                isbalanced[0]=False
                return 0
            
            return max(left,right)+1
        
        height(root)
        return isbalanced[0]