#include <set>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    set<int> s(nums.begin(), nums.end());
    return s.size() != nums.size();
}