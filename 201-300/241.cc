#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

vector<int> diffWaysToCompute(string expression)
{
    vector<string> exp_vector = split(expression);
    int size = exp_vector.size(), num_size = (size + 1) / 2, offset = 0;
    vector<vector<vector<int>>> dp(num_size, vector<vector<int>>(num_size));

    while (offset < num_size)
    {
        for (int i = 0; i < num_size && i + offset < num_size; i++)
        {
            int j = i + offset;
            if (j == i)
                dp[i][j].push_back(stoi(exp_vector[i * 2]));
            for (int k = i; k <= j - 1; k++)
            {
                string op = exp_vector[2 * k + 1]; // 简单的规律，很容易找出
                for (auto x : dp[i][k])
                    for (auto y : dp[k + 1][j])
                        dp[i][j].push_back(operation(op, x, y));
            }
        }
        offset++;
    }

    return dp[0][num_size - 1];
}

vector<string> split(string s)
{
    vector<string> ret;
    int size = s.size(), left = 0, right = 0;
    while (right++ < size)
    {
        if (s[right] == '+' || s[right] == '-' || s[right] == '*')
        {
            ret.push_back(s.substr(left, right - left));
            ret.push_back(s.substr(right++, 1));
            left = right;
        }
    }
    ret.push_back(s.substr(left, right - left));
    return ret;
}

int operation(string op, int a, int b)
{
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    else
        return a * b;
}

int main()
{
    string s = "21-133-144*255*32+24";
    vector<string> v = split(s);
    for (auto &ss : v)
    {
        cout << ss << endl;
    }
}