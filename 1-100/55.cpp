#include <vector>
#include <algorithm>
using namespace std;
bool canJump(vector<int> &nums)
{
    // dp 表示第i个位置最远可达的地方

    int n = nums.size();
    int *dp = new int[n]();
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] < i)
            return false;
        dp[i] = dp[i - 1] >= i + nums[i] ? dp[i - 1] : i + nums[i];
    }

    return dp[n - 1] >= nums[n - 1];
}