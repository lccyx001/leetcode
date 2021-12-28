# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):

    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not postorder:
            return None
        if len(postorder) == 1:
            return TreeNode(postorder[0])
        root = TreeNode(postorder[-1])
        pos = inorder.index(postorder[-1])
        root.left = self.buildTree(
            inorder[:pos], postorder[:len(inorder[:pos])])
        root.right = self.buildTree(
            inorder[pos+1:], postorder[len(inorder[:pos]):-1])
        return root
