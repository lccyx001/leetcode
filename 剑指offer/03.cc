#include <algorithm>
#include <vector>
using namespace std;
int findRepeatNumber(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i - 1] == nums[i]) return nums[i];
  }
  return nums[nums.size() - 1];
}