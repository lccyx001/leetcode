#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<vector<int>> largeGroupPositions(string s)
{
    char last = s[0];
    s += " ";
    int n = s.size(), cnt = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == last)
        {
            cnt++;
        }
        else if (cnt >= 3)
        {
            ans.push_back({i - cnt, i - 1});
            cnt = 1;
            last = s[i];
        }
        else
        {
            cnt = 1;
            last = s[i];
        }
    }
    return ans;
}

int main()
{
    string a = "";
    auto b = largeGroupPositions(a);
    for (auto &i : b)
    {
        cout << i[0] << "  " << i[1] << endl;
    }
}