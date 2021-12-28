#include "../common.hh"
using namespace std;

vector<vector<int>> levelOrderBottom(TreeNode* root) {
  if (!root) return {};
  queue<TreeNode*> q1, q2;
  vector<int> tmp;
  TreeNode* cur;
  vector<vector<int>> ans;
  q1.push(root);
  while (q1.size() > 0) {
    cur = q1.front();
    q1.pop();
    tmp.push_back(cur->val);
    if (cur->left) q2.push(cur->left);
    if (cur->right) q2.push(cur->right);
    if (q1.size() == 0) {
      ans.push_back(tmp);
      tmp.clear();
      swap(q1, q2);
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}