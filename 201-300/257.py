# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        ans_path = []

        def dfs(root, pathstr):
            if not root:
                ans_path.append(pathstr[:])
                return
            pathstr += "->"+root.val
            dfs(root.left)
            tmp = pathstr.split("->")[:-1]
            pathstr = "->".join(tmp)
            dfs(root.right)
        dfs(root, "")
        return ans_path
