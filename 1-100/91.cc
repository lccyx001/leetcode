#include <string>
#include <iostream>
using namespace std;
int numDecodings(string s)
{
    int n = s.size();
    if (n == 0 || n == 1)
        return s == "0" ? 0 : 1;
    if (s[0] == '0')
        return 0;
    int *dp = new int[n]();
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0' && s[i-1] - '2' > 0)
            return 0;
        else if (s[i] == '0')
            dp[i] = dp[i - 1];
        else if (s[i - 1] == '1')
            dp[i] = dp[i - 1] + 1;
        else if (s[i - 1] == '2' && s[i] - '6' <= 0)
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = dp[i - 1];
    }
    return dp[n - 1];
}

int main()
{
    string a = "12";
    cout << numDecodings(a);
}