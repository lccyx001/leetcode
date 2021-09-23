#include <vector>
#include <algorithm>
using namespace std;
int jump(vector<int> &nums)
{
    // dp[i] 代表到达第i个位置的最少次数，则第i个位置可以到达的走法可以从 dp[i-nums[i]] ~ dp[i-1] 中选出的可以到达i的最小走法
    // 假设nums = {1,2,3,4,5} 最后一个位置i=4可以由 i=0,1,2,3 等备选答案中选出 dp[0]=1(舍弃，因为dp[0]+nums[0]<4)
    // dp[1] = 2(舍弃),dp[2]=2,dp[3]=2,dp[4]=3

    // [2,3,1,1,4] n=5

    int maxPos = 0, n = nums.size(), end = 0, step = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (maxPos >= i)
        {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end)
            {
                end = maxPos;
                ++step;
            }
        }
    }
    return step;
}