class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices or len(prices)==1:
            return 0

        n = len(prices)
        min_price = int(10e5)
        dp = [0 for _ in range(n+1)]
        for i in range(1,n+1):
            if min_price > prices[i-1]:
                min_price = prices[i-1]
            dp[i] = max(dp[i-1],prices[i-1]-min_price)
            
        return dp[n]