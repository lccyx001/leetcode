#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int findTargetSumWays(vector<int> &nums, int target)
{
    int sum = 0;
    for (auto &n : nums)
    {
        sum += n;
    }
    if ((target + sum) & 1 != 0 || sum < target)
    {
        return 0;
    }

    vector<int> dp((target + sum) / 2 + 1, 0);
    dp[0] = 1;
    for (auto &n : nums)
    {
        for (int j = dp.size() - 1; j >= n; --j)
        {
            dp[j] += dp[j - n];
        }
    }
    return dp.back();
}