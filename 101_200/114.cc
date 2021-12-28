
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if not root:return None
        res = []
        def dfs(root):
            if not root:return
            res.append(root)
            if root.left:dfs(root.left)
            if root.right:dfs(root.right)
        dfs(root)
        cur = first = TreeNode(0,None)
        for node in res:
            cur.left,cur.right = None,node
            cur = cur.right
        return root

            
            
        
            
