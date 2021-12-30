class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices or len(prices)==1:
            return 0

        n = len(prices)
        dp =[[ 0 for _ in range(2) ] for _ in range(n+1)]
        # dp =[]
        # for i in range(n+1):
        #     dp.append([])
        #     for j in range(2):
        #         dp[i].append(0)

        dp[0][0] = 0
        dp[0][1] = -prices[0]
        for i in range(1,n+1):
            dp[i][0] = max(dp[i-1][1]+prices[i-1], dp[i-1][0])
            dp[i][1] = max(dp[i-1][0]-prices[i-1], dp[i-1][1])

        return dp[n][0]