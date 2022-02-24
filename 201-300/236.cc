#include "common.hh"
using namespace std;
bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
  if (root == nullptr) return false;
  bool lson = dfs(root->left, p, q, ans);
  bool rson = dfs(root->right, p, q, ans);
  if ((lson && rson) ||
      (root->val == p->val || root->val == q->val) && (lson || rson))
    ans = root;
  return lson || rson || (root->val == p->val || root->val == q->val);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode* ans;
  dfs(root, p, q, ans);
  return ans;
}