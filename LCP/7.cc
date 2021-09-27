#include <vector>
using namespace std;

int numWays(int n, vector<vector<int>> &relation, int k)
{
    vector<vector<int>> dp(k + 1, vector<int>(n));
    dp[0][0] = 1;
    for (int i = 0; i < k; i++)
    {
        for (auto &edge : relation)
        {
            int src = edge[0], dst = edge[1];
            dp[i + 1][dst] += dp[i][src];
        }
    }
    return dp[k][n - 1];
}