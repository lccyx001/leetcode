#include "common.hh"
using namespace std;
int removeDuplicates(vector<int>& nums) {
  int cnt = 0;
  for (int i = nums.size() - 1; i >= 2; i--) {
    if (nums[i - 1] == nums[i] && nums[i - 2] == nums[i]) {
      for (int j = i; j < nums.size() - cnt - 1; j++) {
        nums[j] = nums[j + 1];
      }
      cnt++;
    }
  }
  return nums.size() - cnt;
}