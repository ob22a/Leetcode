# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: Optional[TreeNode]
        :type q: Optional[TreeNode]
        :rtype: bool
        """
        s1,s2=list([p]),list([q])
        while s1 or s2:
            node1=s1.pop()
            node2=s2.pop()
            if node1 and node2:
                if node1.val!=node2.val:
                    return False
                s1.append(node1.right)
                s1.append(node1.left)
                s2.append(node2.right)
                s2.append(node2.left)
            else:
                if node1!=node2:
                    return False
        return True