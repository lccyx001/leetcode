#include "common.hh"
using namespace std;
int longestConsecutive(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  if (n <= 1) return nums.size();
  int mx_cnt = 0, cnt = 1;
  for (int i = 1; i < n; i++) {
    if (nums[i] - nums[i - 1] > 1) {
      mx_cnt = max(mx_cnt, cnt);
      cnt = 1;
      continue;
    }
    if (nums[i] - nums[i - 1] == 1) cnt++;
  }
  return max(mx_cnt, cnt);
}