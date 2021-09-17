#include <string>
#include <iostream>
using namespace std;
bool backspaceCompare(string s, string t)
{
    string ss = "", tt = "";
    for (auto &si : s)
    {
        if (si == '#')
            ss = ss.substr(0, ss.size() - 1);
        else
            ss += si;
    }
    for (auto &ti : t)
    {
        if (ti == '#')
            tt = tt.substr(0, tt.size() - 1);
        else
            tt += ti;
    }
    cout << ss << endl
         << tt << endl;
    return ss == tt;
}

int main()
{
    string a = "ab#c", b = "ad#c";
    bool s = backspaceCompare(a, b);
    cout << s;
}