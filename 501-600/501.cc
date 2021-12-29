#include "common.hh"
using namespace std;
void dfs(TreeNode* root, map<int, int>& m) {
  if (!root) return;
  if (m.count(root->val) > 0)
    m[root->val]++;
  else
    m.insert({root->val, 1});
  if (root->left) dfs(root->left, m);
  if (root->right) dfs(root->right, m);
}

vector<int> findMode(TreeNode* root) {
  map<int, int> m;
  vector<int> ans;
  dfs(root, m);
  int mx = 0;
  for (auto i = m.begin(); i != m.end(); i++) {
    mx = max(mx, i->second);
  }
  for (auto i = m.begin(); i != m.end(); i++) {
    if (i->second == mx) ans.push_back(i->second);
  }

  return ans;
}