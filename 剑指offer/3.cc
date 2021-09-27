#include <vector>
using namespace std;
vector<int> countBits(int n)
{
    vector<int> ans;
    int cnt = 0, j = 0;
    for (int i = 0; i <= n; i++)
    {
        j = i;
        while (j > 0)
        {
            if (j & 1)
                cnt++;
            j >>= 1;
        }
        ans.push_back(cnt);
        cnt = 0;
    }
    return ans;
}