#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
string shortestCompletingWord(string licensePlate, vector<string> &words)
{
    unordered_map<char, int> mp;
    for (auto &l : licensePlate)
    {
        if (isalpha(l))
        {
            if (mp.count(tolower(l)))
                mp[tolower(l)]++;
            else
                mp[tolower(l)] = 1;
        }
    }

    string ans = "";
    for (string &s : words)
    {
        bool find = true;
        for (auto &mppair : mp)
        {
            int cnt = 0;
            for (auto &&si : s)
            {
                if (tolower(si) == mppair.first)
                    cnt++;
            }
            if (cnt < mppair.second)
            {
                find = false;
                break;
            }
        }
        if (find && (ans.size() > s.size() || ans.size() == 0))
            ans = s;
    }
    return ans;
}

int main()
{
    string a = "1s3 PSt";

    vector<string> v;
    v.push_back("step");
    v.push_back("steps");
    v.push_back("stripe");
    v.push_back("stepple");
    cout << shortestCompletingWord(a, v);
}