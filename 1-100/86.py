# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        smallh, largeh = ListNode(0), ListNode(0)
        small, large = smallh, largeh
        while head:
            if head.val >= x:
                largeh.next = head
                largeh = largeh.next
            else:
                smallh.next = head
                smallh = smallh.next
            head = head.next
        smallh.next = large.next
        largeh.next = None
        return small.next
