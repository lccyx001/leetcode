#include "common.hh"
using namespace std;
void dfs(TreeNode* root, int& cnt) {
  if (!root) return;
  cnt++;
  if (root->left) dfs(root->left, cnt);
  if (root->right) dfs(root->right, cnt);
}

int countNodes(TreeNode* root) {
  int ans = 0;
  dfs(root, ans);
  return ans;
}