#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][1] = -prices[0]; // 第1天，持有股票的最大收益
    dp[0][0] = 0;          // 第i天，不持有股票的最大收益
    if (n == 2)
    {
        dp[1][0] = max(dp[0][1] + prices[1], dp[0][0]);
        dp[1][1] = dp[0][0] - prices[1];
        return max(dp[1][0], dp[1][1]);
    }

    for (int i = 2; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = dp[i - 2][0] - prices[i];
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}