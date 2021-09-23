#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;
bool buddyStrings(string a, string b)
{
    if (a.size() != b.size())
        return false;
    int n = a.size();
    if (a != b)
    {
        // 记录两个不等对应的序号
        int first = -1;
        int second = -1;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
            {
                if (first == -1)
                {
                    first = i;
                }
                else if (second == -1)
                {
                    second = i;
                }
                else
                {
                    // 有2个以上的不等的情况，直接返回失败
                    return false;
                }
            }
        }
        return (second != -1) && (a[first] == b[second]) && (a[second] == b[first]);
    }
    else
    {
        int cnt[26] = {0};
        for (int i = 0; i < n; ++i)
        {
            if (++cnt[a[i] - 'a'] >= 2)
                return true;
        }
        return false;
    }
}