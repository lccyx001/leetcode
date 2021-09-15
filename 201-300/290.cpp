#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> chstr;
    unordered_map<string, char> strch;
    int n = pattern.size();
    vector<string> vec;
    int pos1 = 0, pos2 = s.find(" ");
    while (pos2 != string::npos)
    {
        vec.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = s.find(" ", pos1);
    }
    if (pos1 != s.length())
        vec.push_back(s.substr(pos1));

    if (vec.size() != n)
        return false;
    for (int i = 0; i < n; i++)
    {
        char x = pattern[i];
        string y = vec[i];
        if ((chstr.count(x) && chstr[x] != y) || (strch.count(y) && strch[y] != x))
            return false;
        chstr[x] = y;
        strch[y] = x;
    }
    return true;
}