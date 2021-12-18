#include "common.hh"
using namespace std;

vector<vector<int>> combine(int n, int k) {
  vector<int> used(n + 1, 0);
  set<vector<int>> maps;
  vector<vector<int>> ans;
  vector<int> tmp;
  dfs(tmp, ans, used, n, k, 0);
  return ans;
}

void dfs(vector<int>& tmp, vector<vector<int>>& ans, vector<int>& used, int n,
         int k, int idx) {
  if (tmp.size() == k) {
    ans.push_back(tmp);
    return;
  }
  for (int i = idx + 1; i <= n; i++) {
    if (used[i]) continue;
    used[i] = 1;
    tmp.push_back(i);
    dfs(tmp, ans, used, n, k, i);
    used[i] = 0;
    tmp.pop_back();
  }
}