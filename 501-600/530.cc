#include "common.hh"
using namespace std;
void dfs(TreeNode* root, vector<int>& ans) {
  if (!root) return;
  if (root->left) dfs(root->left, ans);
  ans.push_back(root->val);
  if (root->right) dfs(root->right, ans);
}

int getMinimumDifference(TreeNode* root) {
  if (!root) return 0;
  vector<int> vec;
  int ans = INT_MAX;
  dfs(root, vec);
  for (int i = 0; i < vec.size() - 1; i++) {
    ans = min(ans, abs(vec[i] - vec[i + 1]));
  }
  return ans;
}