#include <string>
#include <vector>
#include <iostream>
using namespace std;
int minFlipsMonoIncr(string s)
{
    int n = s.size();
    vector<vector<int>> dp(2, vector<int>(n + 1, INT64_MAX));
    dp[0][0] = 0;
    dp[1][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = s[i - 1] == '0' ? dp[0][i - 1] : dp[0][i - 1] + 1;
        if (s[i - 1] == '0')
        {
            dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + 1;
        }
        else
        {
            dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]);
        }
    }

    return min(dp[0][n], dp[1][n]);
}

int main()
{
    string a = "00110";
    minFlipsMonoIncr(a);
}