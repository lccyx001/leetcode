
#include <string>
#include <iostream>
using namespace std;
bool detectCapitalUse(string word)
{
    int n = word.size(), cond1 = 0, cond2 = 0, cond3 = 0;
    //1 首字母 2 全小 3 全大
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && isupper(word[i]))
        {
            cond1++;
            continue;
        }
        if (isupper(word[i]))
            cond3++;
        else
            cond2++;
    }

    if (cond1 + cond2 == n || cond2 == n || cond3 + cond1 == n)
        return true;
    return false;
}

int main()
{
    // cout << isupper('U');
    cout << detectCapitalUse("USA") << endl;
}