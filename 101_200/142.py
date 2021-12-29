# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow, fast = head, head
        while fast and fast.next and fast.next.next:
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                start = head
                while start != slow:
                    start, slow = start.next, slow.next
                return start
        return None