#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int numSquares(int n)
{
    vector<int> dp(n + 1, 10001);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; pow(j, 2) <= n && i >= pow(j, 2); j++)
        {
            dp[i] = min(dp[i], dp[i - pow(j, 2)] + 1);
        }
    }
    return dp[n];
}

int main()
{
    cout << numSquares(13) << endl;
}
