#include <string>
#include <vector>
using namespace std;

vector<int> numberOfLines(vector<int> &widths, string s)
{
    int line = 0, cnt = 0;
    for (auto &si : s)
    {
        cnt += widths[si - 'a'];
        if (cnt > 100)
        {
            line++;
            cnt = widths[si - 'a'];
        }
    }

    if (cnt > 0)
        line++;
    else
        cnt = 100;

    return {line, cnt};
}