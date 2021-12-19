#include "common.hh"
using namespace std;

void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& p,
         set<vector<int>>& cs, int idx) {
  if (cs.count(p) == 0) {
    cs.insert(p);
    ans.push_back(p);
  }

  for (int i = idx; i < nums.size(); i++) {
    p.push_back(nums[i]);
    dfs(nums, ans, p, cs, i + 1);
    p.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  set<vector<int>> checkset;
  vector<vector<int>> ans;
  vector<int> p;
  dfs(nums, ans, p, checkset, 0);
  return ans;
}

int main() {
  vector<int> a({1, 2, 2});
  vector<vector<int>> ans = subsetsWithDup(a);
}