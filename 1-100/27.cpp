#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    vector<int> numt;
    for (auto &i : nums)
    {
        if (i != val)
            numt.push_back(i);
    }
    nums.assign(numt.begin(), numt.end());
    return nums.size();
}