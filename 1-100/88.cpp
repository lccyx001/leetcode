#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int cnt = 0;
    for (auto &i : nums2)
    {
        nums1[m + cnt++] = i;
    }
    sort(nums1.begin(), nums1.end());
}