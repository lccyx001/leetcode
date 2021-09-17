#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    set<int> st(nums.begin(), nums.end());
    nums.assign(st.begin(), st.end());
    sort(nums.begin(), nums.end());
    return st.size();
}