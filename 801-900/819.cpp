#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string mostCommonWord(string paragraph, vector<string> &banned)
{
    int pn = paragraph.size();
    string word = "";
    unordered_map<string, int> mp;
    for (int i = 0; i < pn; i++)
    {

        if (isalpha(paragraph[i]))
            word += tolower(paragraph[i]);
        else
        {
            if (word == "")
                continue;
            if (find(banned.begin(), banned.end(), word) != banned.end())
            {
                word = "";
                continue;
            }
            if (mp.count(word))
                mp[word]++;
            else
                mp[word] = 1;
            word = "";
        }
    }

    if (word.size() && find(banned.begin(), banned.end(), word) == banned.end())
    {
        if (mp.count(word))
            mp[word]++;
        else
            mp[word] = 1;
    }

    int most = 0;
    string ans = "";
    for (auto &mi : mp)
    {
        // cout << mi.first << " " << mi.second << endl;
        if (mi.second > most)
        {
            ans = mi.first;
            most = mi.second;
        }
    }
    return ans;
}

int main()
{
    string s = "Bob. hIt, baLl";
    vector<string> v;
    v.push_back("hit");
    v.push_back("bob");
    cout << mostCommonWord(s, v);
}