#include <string>
#include <iostream>
using namespace std;
string reverseStr(string s, int k)
{
    int n = s.size();
    int i = 0, cnt = 0;
    while (i < n)
    {
        cnt++;
        if (cnt == k * 2)
        {
            for (int j = 0; j < k / 2; j++)
            {
                char tmp = s[i - cnt + j + 1];
                s[i - cnt + j + 1] = s[i - k - j];
                s[i - k - j] = tmp;
            }
            cnt = 0;
        }
        i++;
    }
    if (cnt == 0)
        return s;
    if (cnt < k)
    {
        for (int j = 0; j < cnt / 2; j++)
        {
            char tmp = s[i - cnt + j];
            s[i - cnt + j] = s[i - j - 1];
            s[i - j - 1] = tmp;
        }
    }
    else
    {
        // i=10 j=0 k=3 cnt=4
        for (int j = 0; j < k / 2; j++)
        {
            char tmp = s[i - cnt + j];
            s[i - cnt + j] = s[i - cnt + k - j - 1];
            s[i - cnt + k - j - 1] = tmp;
        }
    }
    return s;
}

int main()
{
    string s = "abcdefghij";
    string s1 = "abcdef";
    string s2 = "abcdefhi";
    cout << reverseStr(s, 3);
}