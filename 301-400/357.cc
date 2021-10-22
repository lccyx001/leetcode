#include <vector>
#include <math.h>
using namespace std;

int countNumbersWithUniqueDigits(int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] * 10 + (9 * pow(10, i - 2) - dp[i - 1]) * (i - 1);
    }

    
    int sum = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        sum += dp[i];
    }
    return pow(10, n) - sum;
}