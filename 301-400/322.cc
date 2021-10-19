#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    int max_int = amount + 1;
    vector<int> dp(max_int, max_int);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i >= coins[j])
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    return dp[amount] == max_int ? -1 : dp[amount];
}

int main()
{
    vector<int> v;
    // v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    cout << coinChange(v, 11);
}