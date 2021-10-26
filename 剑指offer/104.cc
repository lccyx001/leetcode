#include <vector>
using namespace std;

int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(0, target);

    // dp[n] = n + dp[n - i]
}