#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool isInterleave(string s1, string s2, string s3)
{
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n1 + n2 != n3)
        return false;

    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < n1 + 1; i++)
    {
        for (int j = 0; j < n2 + 1; j++)
        {
            if (0 <= i - 1 && s1[i - 1] == s3[i + j - 1])
            {
                dp[i][j] = dp[i - 1][j] | dp[i][j];
            }

            if (0 <= j - 1 && s2[j - 1] == s3[i + j - 1])
            {
                dp[i][j] = dp[i][j - 1] | dp[i][j];
            }
        }
    }

    return dp[n1][n2];
}

int main()
{
    string a = "1234";
    bool s = a.substr(0, 3) + "4" == a;
    cout << s;
}