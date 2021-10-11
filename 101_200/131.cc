#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<vector<string>> answers;
vector<string> ans;
bool ispal(string s)
{
    if (s.size() == 0 || s.size() == 1)
        return true;
    return ispal(s.substr(1, s.size() - 2)) && s[0] == s[s.size() - 1];
}

void dfs(string s, int pos)
{
    if (pos == s.size())
    {
        vector<string> tmp;
        for (auto &a : ans)
            tmp.push_back(a);
        answers.push_back(tmp);
        return;
    }
    for (int i = pos + 1; i <= s.size(); i++)
    {
        if (ispal(s.substr(pos, i - pos)))
        {
            ans.push_back(s.substr(pos, i - pos));
            dfs(s, i);
            ans.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    dfs(s, 0);
    return answers;
}
int main()
{
    string a = "aab";
    vector<vector<string>> b = partition(a);
    for (auto &&i : b)
    {
        cout << i.size() << "  ";
        for (auto &s : i)
        {
            cout << s << "   ";
        }
        cout << endl;
    }

    cout << b.size();
}