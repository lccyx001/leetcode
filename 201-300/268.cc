#include <vector>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int n = nums.size(), s = (1 + n) * n / 2;
    for (auto &ni : nums)
    {
        s -= ni;
    }
    return s;
}