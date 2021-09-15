#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    int n = s.size();
    int a[26] = {0}, b[26] = {0};
    for (int i = 0; i < n; i++)
    {

        a[tolower(s[i]) - 'a']++;
        b[tolower(t[i]) - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

int main()
{
    cout << isAnagram("egg", "gge");
}