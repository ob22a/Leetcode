# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def hasPathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: bool
        """
        if not root:
            return False
        stack=[(root,root.val)]
        while stack:
            node,val=stack.pop()
            if not node.left and not node.right:
                if val==targetSum:
                    return True
            else:
                if node.left:
                    stack.append((node.left,val+node.left.val))
                if node.right:
                    stack.append((node.right,val+node.right.val))
        return False