class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        maps = {"]":"[","}":"{",")":"("}
        for al in s:
            if al not in maps.keys():
                stack.append(al)
            else:
                if len(stack) <1:
                    return False
                if stack[-1] == maps.get(al):
                    stack.pop()
                else:return False
        if len(stack)>0:return False
        return True