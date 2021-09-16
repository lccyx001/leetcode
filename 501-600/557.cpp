#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string reverseWords(string s)
{
    int n = s.size(), pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            reverse(&s[pos], &s[i]);
            pos = i + 1;
        }
    }
    if (pos != n - 1)
        reverse(&s[pos], &s[n]);

    return s;
}

int main()
{
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s);
}