#include <vector>
#include <algorithm>
using namespace std;
int lenLongestFibSubseq(vector<int> &arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); ++i)
    {
        mp[arr[i]] = i;
    }

    int ret = 0;
    for (int i = 1; i < arr.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int temp = arr[i] - arr[j];
            // 存在 k 使得 A[i] = A[j] + A[k] (0 <= k < j < i)
            if (mp.count(temp) && mp[temp] < j)
            {
                dp[i][j] = dp[j][mp[temp]] + 1;
            }
            // 不存在 k 使得 A[i] = A[j] + A[k] (0 <= k < j < i)
            else
            {
                dp[i][j] = 2;
            }
            ret = max(ret, dp[i][j]);
        }
    }

    return ret > 2 ? ret : 0;
}