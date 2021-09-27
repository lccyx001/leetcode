#include <vector>
#include <string>
using namespace std;
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

vector<vector<string>> partition(string s)
{
}