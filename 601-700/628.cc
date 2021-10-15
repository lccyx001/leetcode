#include <vector>
using namespace std;
int maximumProduct(vector<int> &nums)
{
    int maxpro = -__INT64_MAX__;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; i < nums.size(); j++)
        {
            for (int k = 0; i < nums.size(); k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                maxpro = max(maxpro, nums[i] * nums[j] * nums[k]);
            }
        }
    }
    return maxpro;
}