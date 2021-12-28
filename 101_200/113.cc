#include "common.hh"
using namespace std;
void dfs(TreeNode* root, int targetSum, vector<int>& p,
         vector<vector<int>>& ans) {
  if (!root) return;
  p.push_back(root->val);
  if (!root->left && !root->right) {
    if (accumulate(p.begin(), p.end(), 0) == targetSum) ans.push_back(p);
    return;
  }
  if (root->left) {
    dfs(root->left, targetSum, p, ans);
    p.pop_back();
  }
  if (root->right) {
    dfs(root->right, targetSum, p, ans);
    p.pop_back();
  }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
  if (!root) return {};
  vector<vector<int>> ans;
  vector<int> p;
  dfs(root, targetSum, p, ans);
  return ans;
}
