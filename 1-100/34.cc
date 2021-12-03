#include "common.hh"
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
  int n = nums.size();
  if (n == 0) return {-1, -1};
  vector<int> ans;
  for (int i = 0; i < n ; i++) {
    if (nums[i] < target) continue;
    if (nums[i] == target) ans.push_back(i);
    if (nums[i] > target) break;
  }
  if (ans.size() == 0) return {-1, -1};
  return {ans[0], ans[ans.size() - 1]};
}
int main() {
  vector<int> a(1, 1);
  searchRange(a,1);
}