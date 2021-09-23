#include <vector>
#include <algorithm>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt = 0, j = 0, i = 0, gn = g.size(), sn = s.size();

    while (j < sn && i < gn)
    {
        if (g[i] <= s[j])
        {
            cnt++;
            i++;
            j++;
            continue;
        }
        j++;
    }

    return cnt;
}
