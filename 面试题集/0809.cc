#include <vector>
#include <string>
#include <iostream>
using namespace std;

void dfs(string s, vector<string> &ans, int left, int right, int n)
{
    if (right > left || left > n)
        return;

    if (s.size() == n * 2)
    {
        ans.push_back(s);
        return;
    }
    dfs(s + "(", ans, left + 1, right, n);
    dfs(s + ")", ans, left, right + 1, n);
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    dfs("", ans, 0, 0, n);
    return ans;
}

int main()
{
    vector<string> ans = generateParenthesis(3);
    for (auto &a : ans)
    {
        cout << a << endl;
    }
}