#include <string>
#include <vector>
#include <iostream>
using namespace std;

void split(string s, vector<string> &v, string spacer)
{
    int pos1, pos2, n = spacer.length();
    pos1 = 0;
    pos2 = s.find(spacer);
    while (pos2 != string::npos)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + n;
        pos2 = s.find(spacer, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

void trim(string &s)
{
    if (s.empty())
        return;

    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}

int lengthOfLastWord(string s)
{
    trim(s);
    vector<string> v;
    split(s, v, " ");
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return v[v.size() - 1].size();
}

int main()
{
    string s = "   fly me   to   the moon  ";
    int a = lengthOfLastWord(s);
    cout << a << endl;
}