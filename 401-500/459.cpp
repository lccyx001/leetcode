#include <string>
#include <iostream>
using namespace std;
bool repeatedSubstringPattern(string s)
{
    int n = s.size(), j, len;
    string sub;
    for (int i = 1; i < n; i++)
    {
        sub = s.substr(0, i);
        j = len = i;
        while (j < n && j + len <= n)
        {
            if (s.substr(j, len) != sub)
                break;
            j += len;
        }
        if (j == n)
            return true;
    }
    return false;
}

int main()
{
    string a = "ababab";
    // cout << a.substr(0, 1) << " " << a.substr(1, 1);
    cout << repeatedSubstringPattern(a);
}