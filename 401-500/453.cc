#include <vector>
#include <algorithm>
using namespace std;

int minMoves(vector<int> &nums)
{

    int minNum = *min_element(nums.begin(), nums.end()), res = 0;
    for (int num : nums)
    {
        res += num - minNum;
    }
    return res;
}