#include "common.hh"
using namespace std;

int gainPriority(TreeNode* root, int& maxpath) {
  if (!root) return 0;
  int left = max(gainPriority(root->left, maxpath), 0);
  int right = max(gainPriority(root->right, maxpath), 0);
  int cur = root->val + left + right;
  maxpath = max(cur, maxpath);
  return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
  int maxpath = INT64_MIN;
  gainPriority(root, maxpath);
  return maxpath;
}