#include <vector>
using namespace std;
int rob(vector<int> &nums)
{
    int n = nums.size(), stole = 0, nstole = 0;
    for (int i = 1; i <= n; i++)
    {
        int nownstole = max(nstole, stole);
        int nowstole = nstole + nums[i - 1];
        stole = nowstole;
        nstole = nownstole;
    }
    return max(stole, nstole);
}