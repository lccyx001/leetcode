#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            if (dp[i] && find(wordDict.begin(), wordDict.end(), s.substr(i, j - i)) != wordDict.end())
                dp[j] = true;
        }
    }

    return dp[n];
}

int main()
{
    string s = "leetcode";
    vector<string> wordDict;
    wordDict.push_back("leet");
    wordDict.push_back("code");
    bool l = wordBreak(s, wordDict);
    cout << l;
}