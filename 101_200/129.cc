#include "common.hh"
using namespace std;
void dfs(TreeNode* root, int sum, int& ans) {
  if (!root) return;
  if (!root->left && !root->right) {
    ans += sum * 10 + root->val;
    return;
  }
  if (root->left) dfs(root->left, sum * 10 + root->val, ans);
  if (root->right) dfs(root->right, sum * 10 + root->val, ans);
}

int sumNumbers(TreeNode* root) {
  int sum = 0, ans = 0;
  dfs(root, sum, ans);
  return ans;
}