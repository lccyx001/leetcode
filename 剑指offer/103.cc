#include <vector>
#include <iostream>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    // dp[i] 组成钱数i的硬币最小数
    vector<int> dp(amount + 1, __INT_MAX__);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] < __INT_MAX__)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
        cout << i << "   " << dp[i] << endl;
    }

    return dp[amount] == __INT_MAX__ ? -1 : dp[amount];
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(5);
    coinChange(a, 11);
}