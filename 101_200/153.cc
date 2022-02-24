#include "common.hh"
using namespace std;
class Solution {
 public:
  int findMin(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[0];
  }
};