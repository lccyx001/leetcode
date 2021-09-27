#include <vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = obstacleGrid[0][0] == 1 ? 0 : 1;
                continue;
            }

            if (i == 0)
            {
                if (obstacleGrid[i][j] != 1)
                    dp[0][j] = dp[0][j - 1];
                else
                    dp[0][j] = 0;
                continue;
            }

            if (j == 0)
            {
                if (obstacleGrid[i][j] != 1)
                    dp[i][0] = dp[i - 1][0];
                else
                    dp[i][0] = 0;
                continue;
            }

            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}