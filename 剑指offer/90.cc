#include <vector>
#include <algorithm>
using namespace std;

int robRange(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    for (int i = 1; i <= nums.size(); i++)
    {
        dp[1][i] = max(dp[0][i - 1] + nums[i - 1], dp[1][i - 1]);
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }
    return max(dp[1][n], dp[0][n]);
}

int rob(vector<int> &nums)
{
    if (nums.size() <= 2)
        return *max_element(nums.begin(), nums.end());
    vector<int> p1(nums.begin() + 1, nums.end());
    vector<int> p2(nums.begin(), nums.end() - 1);
    return max(robRange(p1), robRange(p2));
}
