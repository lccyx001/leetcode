#include <string>
#include <algorithm>
using namespace std;
string licenseKeyFormatting(string s, int k)
{
    string buf, ans;
    for (auto &si : s)
        if (si != '-')
            buf += toupper(si);
    int n = buf.size(), mod, cnt = 0;
    mod = n % k;
    for (int i = 0; i < n; i++)
    {
        ans += buf[i];
        cnt++;
        if ((i + 1 == mod || cnt % k == 0) && i != n - 1)
        {
            ans += "-";
            cnt = 0;
        }
    }
    return ans;
}
