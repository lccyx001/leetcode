#include "common.hh"
using namespace std;
int search(vector<int>& nums, int target) {
  int n = nums.size();
  if (nums[0] > target && nums[n - 1] < target) return -1;
  if (nums[0] <= target) {
    for (int i = 0; i < n; i++) {
      if (nums[i] > target) return -1;
      if (nums[i] == target) return i;
    }
    return -1;
  } else {
    for (int i = n - 1; i > 0; i--) {
      if (nums[i] < target) return -1;
      if (nums[i] == target) return i;
    }
    return -1;
  }
}