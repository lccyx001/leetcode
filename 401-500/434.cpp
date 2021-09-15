#include <string>
#include <vector>
#include <iostream>
using namespace std;

int countSegments(string s)
{
    if (s.find_first_not_of(' ') == string::npos)
        return 0;

    vector<string> v;
    string buf = "";
    for (auto &si : s)
    {
        if (si != ' ')
            buf += si;
        else if (buf.size() != 0)
        {
            v.push_back(buf);
            buf.clear();
        }
    }

    if (buf.size() != 0)
        v.push_back(buf);
    return v.size();
}

int main()
{
    string a = "Of all the gin joints in all the towns in all the world,   ";
    cout << countSegments(a);
}