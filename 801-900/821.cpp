#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<int> shortestToChar(string s, char c)
{
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
        int distance = 100000;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] != c)
                continue;
            distance = distance > abs(i - j) ? abs(i - j) : distance;
        }
        v.push_back(distance);
    }
    return v;
}

int main()
{
    string s = "loveleetcode";
    char c = 'e';
    vector<int> ans;
    ans = shortestToChar(s, c);
    for (auto &a : ans)
    {
        cout << a << endl;
    }
}