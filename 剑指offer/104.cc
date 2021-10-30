#include <vector>
#include <algorithm>
using namespace std;

int combinationSum4(vector<int> &nums, int target)
{
    // dp[i] 以i为目标的数字组合总数
    // dp[i] += dp[i-j] + 1 

    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int &num : nums)
        {
            if (num <= i && dp[i - num] < INT64_MAX - dp[i])
            {
                dp[i] += dp[i - num];
            }
        }
    }
    return dp[target];
}