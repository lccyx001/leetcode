#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> m;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (m.count(s[i]))
            m[s[i]]++;
        else
            m[s[i]] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (m[s[i]] == 1)
            return i;
    }
    
    return -1;
}