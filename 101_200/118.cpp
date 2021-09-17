#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> dp;
    for (int i = 0; i < numRows; i++)
    {
        if (i == 0)
        {
            dp.push_back({1});
            continue;
        }
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                dp.push_back({1});
            else if (j == i)
                dp[i].push_back(1);
            else
            {
                dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
            }
        }
    }
    return dp;
}

int main()
{
    vector<vector<int>> v = generate(5);
    for (auto &ve : v)
    {
        for (auto &vve : ve)
        {
            cout << vve;
        }
        cout << endl;
    }
}