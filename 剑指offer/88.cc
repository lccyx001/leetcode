#include <vector>
#include <iostream>
// #include <math.h>
using namespace std;
int minCostClimbingStairs(vector<int> &cost)
{
    // [10, 15, 20]
    int n = cost.size();
    if (n == 0 || n == 1)
        return 0;
    int *dp = new int[n+1]();
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << dp[i] << endl;
    // }
    return dp[n];
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    cout << minCostClimbingStairs(v);
}