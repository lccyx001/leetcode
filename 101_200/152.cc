#include <vector>
#include <iostream>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        int mx = maxF, mn = minF;
        maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
        minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
        ans = max(maxF, ans);
    }
    return ans;
}

int main()
{
    vector<int> a;
    a.push_back(-2);
    a.push_back(0);
    a.push_back(-1);

    cout << maxProduct(a);
}