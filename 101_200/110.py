# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True

        lheight = self.height(root.left)
        rheight = self.height(root.right)
        if abs(lheight-rheight) > 1:
            return False
        return self.isBalanced(root.left ) and self.isBalanced(root.right)

    def height(self, node):
        if node is None:
            return 0
        rheight = 1 + self.height(node.right)
        lheight = 1 + self.height(node.left)
        if rheight > lheight:
            return rheight 
        else:
            return lheight
