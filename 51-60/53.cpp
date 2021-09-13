#include <vector>
#include <iostream>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int pre = 0, maxAns = nums[0];
    for (const auto &x : nums)
    {
        cout << "before pre:" << pre << "  max:" << maxAns << "  x:" << x << endl;
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
        cout << "end pre:" << pre << "  max:" << maxAns << endl;
    }
    return maxAns;
}

int main()
{
    // int mynums[] = {1};
    // int mynums[] = {-1};
    // int mynums[] = {2, 1};
    // int mynums[] = {-2, -1};
    // int mynums[] = {-2, 2};
    // int mynums[] = {-2, 1};
    int mynums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // int mynums[] = {8, -19, 5, -4, 20};
    vector<int> nums(mynums, mynums + sizeof(mynums) / sizeof(int));
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
    int result = maxSubArray(nums);
    cout << result;
}