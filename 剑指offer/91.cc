#include <vector>
#include <algorithm>
using namespace std;
int minCost(vector<vector<int>> &costs)
{
    int n = costs.size();
    vector<vector<int>> dp(3, vector<int>(n + 1, INT64_MAX));
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + costs[i-1][0];
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + costs[i-1][1];
        dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + costs[i-1][2];
    }
    return min(min(dp[0][n], dp[1][n]), dp[2][n]);
}