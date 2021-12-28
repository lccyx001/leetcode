# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        a = []
        while head:
            a.append(head.val)
            head = head.next
        root = self.recursive(a)
        return root
        
    def recursive(self,array):
        if not len(array):
            return None
        if len(array)==1:
            return TreeNode(array[0])

        root = TreeNode(array[len(array)/2])
        root.left = self.recursive(array[:len(array)/2])
        root.right = self.recursive(array[len(array)/2+1:])
        return root

