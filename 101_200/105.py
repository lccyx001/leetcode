# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder:
            return None
        if len(preorder)==1:
            return TreeNode(preorder[0])
        root = TreeNode(preorder[0])
        pos = inorder.index(preorder[0]) 
        root.left = self.buildTree(preorder[1:1+pos],inorder[:pos])
        root.right = self.buildTree(preorder[1+pos:],inorder[pos+1:])
        return root