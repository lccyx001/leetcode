# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or not head.next or not k:
            return head
        dummpy = ListNode(-1)
        length, dummpy.next, quick, = 0, head, head
        while quick:
            quick = quick.next
            length += 1
        if k >= length:
            k = k % length
        if not k:
            return dummpy.next
        quick, slow, slow_pre, i = head, head, None, 0
        while quick.next:
            quick = quick.next
            if i < k-1:
                i += 1
            else:
                slow, slow_pre = slow.next, slow
        slow_pre.next, dummpy.next, quick.next = None, slow, dummpy.next
        return dummpy.next