# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        if not head.next:
            return head
        cur = head
        first = ListNode(0)
        n = cur.next
        first.next = n
        cur.next = cur.next.next 
        n.next = cur
        cur = cur.next
        n = n.next
        while cur and cur.next:
            n.next = cur.next
            n = cur.next
            cur.next = cur.next.next 
            n.next = cur
            cur = cur.next
            n = n.next
        return first.next