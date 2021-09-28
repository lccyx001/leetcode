#include <vector>
#include <string>
using namespace std;

vector<vector<string>> allstrs;
vector<string> ans;
bool ispal(string s)
{
    int n = s.size();
    if (n == 0 || n == 1)
        return true;

    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

void dfs(string s, int n)
{
    if (n == s.size())
    {
        allstrs.push_back(ans);
        return;
    }

    for (int i = n + 1; i < s.size(); i++)
    {
    }
}

vector<vector<string>> partition(string s)
{
    int n = s.size();
    vector<vector<int>> f(n, vector<int>(n, true));
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        }
    }
    
}