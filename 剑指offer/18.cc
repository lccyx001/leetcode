#include <string>
using namespace std;
bool isPalindrome(string s)
{
    string tmp;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
            tmp.push_back(tolower(s[i]));
    }

    if (tmp.size() == 0)
        return true;
    for (int i = 0, j = tmp.size() - 1; i <= j; i++, j--)
    {
        if (tmp[i] != tmp[j])
            return false;
    }
    return true;
}