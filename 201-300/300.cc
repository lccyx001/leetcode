#include <vector>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int n = nums.size(), ans = 0;

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
