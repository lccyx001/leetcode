# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        dummy=ListNode(0)
        dummy.next=head
        Head=dummy
        for i in range(m-1):
            Head=Head.next
        pre=Head.next
        node=pre.next
        while node and m<n:
            pre.next=node.next
            node.next=Head.next
            Head.next=node
            node=pre.next
            m+=1
        return dummy.next
