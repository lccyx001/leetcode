#include "common.hh"
using namespace std;
vector<int> rightSideView(TreeNode* root) {
  if (!root) return {};
  queue<TreeNode*> q1, q2;
  vector<int> ans;
  TreeNode* cur;
  q1.push(root);
  while (q1.size() > 0) {
    cur = q1.front();
    q1.pop();
    if (cur->left) q2.push(cur->left);
    if (cur->right) q2.push(cur->right);
    if (q1.size() == 0) {
      ans.push_back(cur->val);
      swap(q1, q2);
    }
  }
  return ans;
}