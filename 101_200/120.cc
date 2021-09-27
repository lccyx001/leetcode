#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size(), m = triangle[n - 1].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
                continue;
            }

            if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                continue;
            }
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}