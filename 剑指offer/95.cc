#include <string>
#include <vector>
#include <iostream>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    if (text1 == text2)
        return true;
    if (text2.size() > text1.size())
        swap(text2, text1);
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string text1 = "1234", text2 = "12345";
    swap(text1, text2);
    cout << text1 << endl
         << text2;
}