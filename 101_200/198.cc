#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int rob(vector<int> &nums)
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

int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(7);
    a.push_back(9);
    a.push_back(3);
    a.push_back(1);
    cout << rob(a);
}