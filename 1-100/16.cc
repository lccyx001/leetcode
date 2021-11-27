#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  int ans = nums[0] + nums[1] + nums[2];
  for (int i = 0; i < nums.size() - 2; i++) {
    int left = i + 1, right = nums.size() - 1;
    while (left < right) {
      int tmp = nums[i] + nums[left] + nums[right];
      if (abs(ans - target) > abs(tmp - target)) {
        ans = nums[i] + nums[left] + nums[right];
      }
      if (tmp > target)
        right--;
      else if (tmp < target)
        left++;
      else
        return tmp;
    }
  }

  return ans;
}

int main() {
  vector<int> a({0, 1, 2});
  cout << threeSumClosest(a, 0);
}