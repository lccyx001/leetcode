#include <string>
#include <iostream>
using namespace std;

bool validPalindrome(string s, int start, int end)
{
    for (int i = start, j = end; i < j;)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(string s)
{
    int n = s.size();
    if (n == 0 || n == 1)
        return true;
    bool ans;
    for (int i = 0, j = n - 1; i < j;)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
            continue;
        }

        return validPalindrome(s, i + 1, j) || validPalindrome(s, i, j - 1);
    }

    return true;
}

int main()
{
    string a = "abc";
    cout << validPalindrome(a);
}