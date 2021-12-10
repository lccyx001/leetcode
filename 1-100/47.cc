#include "common.hh"
using namespace std;
void dfs(vector<int>& nums, set<vector<int>>& ans, vector<int> p,
         vector<int>& used) {
  if (p.size() == nums.size()) {
    ans.insert(p);
    return;
  }
  for (int i = 0; i < nums.size(); i++) {
    if (used[i]) continue;
    p.push_back(nums[i]);
    used[i] = 1;
    dfs(nums, ans, p, used);
    p.pop_back();
    used[i] = 0;
  }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
  int n = nums.size();
  vector<int> used(n, 0), p;
  set<vector<int>> ans_s;
  dfs(nums, ans_s, p, used);
  vector<vector<int>> ans;
  for (set<vector<int>>::iterator it = ans_s.begin(); it != ans_s.end(); it++) {
    ans.push_back(*it);
  }
  return ans;
}

int main() {
  set<vector<int>> a;
  a.insert({1, 1});
  a.insert({1, 1});
  cout << a.size();
}