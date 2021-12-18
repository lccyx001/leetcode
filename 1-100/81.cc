#include "common.hh"
using namespace std;
bool ssearch(const vector<int>& nums, int target) {
  if (target >= nums[0])
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > target) return false;
      if (nums[i] == target) return true;
    }
  else if (target < nums[0])
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < target) return false;
      if (nums[i] == target) return true;
    }
  return false;
}

int main() {
  bool t = ssearch({2, 5, 6, 0, 0, 1, 2}, 0);
  cout << t;
}