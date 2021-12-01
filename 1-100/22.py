class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if not n:return []
        def isvalid(s):
            if len(s) %2 == 1:return False
            stack = 0
            for al in s:
                if al == "(":stack+=1
                else:stack-=1
                if stack <0:return False
            return stack == 0

        res = []
        def generate(s):
            if len(s) == n*2:
                if isvalid(s):
                    res.append("".join(s))
                    return 
            if s.count("(")<n:
                generate(s+["("])
            if s.count(")")<n:
                generate(s+[")"])

        generate([])
        return res