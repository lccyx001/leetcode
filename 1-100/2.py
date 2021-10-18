class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        gap = 0
        first = ListNode(0)
        cur = first
        while l1 and l2:
            cur_sum = l1.val + l2.val + gap
            gap = cur_sum / 10
            cur.next = ListNode(cur_sum % 10)  # 卡住了
            cur = cur.next
            l1 = l1.next
            l2 = l2.next
        l = l1 if l1 else l2
        while l:
            cur_sum = l.val + gap
            gap = cur_sum / 10
            cur.next = ListNode(cur_sum % 10)
            cur = cur.next
            l = l.next
        if gap:
            cur.next = ListNode(1)
        return first.next
