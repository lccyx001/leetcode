#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int l = matrix.size(), w = matrix[0].size();
    vector<vector<int>> dp(l + 1, vector<int>(w + 1, 0));
    dp[0][0] = matrix[0][0] - '0';
    for (int i = 1; i < l + 1; i++)
        dp[i][0] = max(matrix[i][0] - '0', dp[i - 1][0]);
    for (int i = 1; i < w + 1; i++)
        dp[0][i] = max(matrix[0][i] - '0', dp[0][i - 1]);

    for (int i = 1; i < l + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            // auto x = matrix[i][j] == '0';
            // cout << x;
            if (matrix[i][j] == '0')
            {
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
                continue;
            }
            bool all1 = true;
            for (int stepi = 1; stepi < min(i, j); stepi++)
            {
                for (int stepj = 1; stepj <= stepi; stepj++)
                {
                    if (matrix[i - stepi][j - stepj] == '0')
                        all1 = false;
                }
                if (all1)
                    dp[i][j] = stepi * stepi;
            }
            dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
        }
        // cout << endl;
    }
    for (auto &ve : dp)
    {
        for (auto &v : ve)
        {
            cout << v;
        }
        cout << endl;
    }

    return dp[l][w];
}

int main()
{
    vector<char> a1{'1', '0', '1', '0', '0'};
    vector<char> a2{'1', '0', '1', '1', '1'};
    vector<char> a3{'1', '1', '1', '1', '1'};
    vector<char> a4{'1', '0', '0', '1', '0'};
    vector<vector<char>> a;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    a.push_back(a4);
    auto x = maximalSquare(a);
    cout << x << endl;
}