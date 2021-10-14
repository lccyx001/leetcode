#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countSquares(vector<vector<char>> &matrix)
{
    int l = matrix.size(), w = matrix[0].size(), squares = 0;
    vector<vector<int>> dp(l, vector<int>(w, 0));
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = matrix[i][j];
            else if (matrix[i][j] == 1)
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            else
                dp[i][j] = 0;
            squares += dp[i][j];
        }
    }
    return squares;
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
    auto x = countSquares(a);
    cout << x << endl;
}