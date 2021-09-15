#include <string>
using namespace std;

char findTheDifference(string s, string t)
{
    int ss = 0, st = 0;
    for (auto &i : s)
        ss += i;

    for (auto &i : t)
        st += i;

    return st - ss;
}