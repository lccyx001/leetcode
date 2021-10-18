from collections import deque
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        alpha_bet = deque()
        length = 0
        for alpha in s:
            if alpha in alpha_bet:
                while alpha in alpha_bet:
                    alpha_bet.popleft()
            alpha_bet.append(alpha)
            length = len(alpha_bet) if len(alpha_bet) > length else length
        return length