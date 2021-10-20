#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int integerBreak(int n)
{

    vector<int> dp(n + 1, 1);
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int maxnum = 0;
        for (int j = 1; j < i; j++)
        {
            maxnum = max(j * (i - j), max(dp[i - j] * j, maxnum));
        }
        dp[i] = maxnum;
    }
    return dp[n];
}

int main()
{
    cout << integerBreak(10);
}