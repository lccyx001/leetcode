#include "../common.hh"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
  if (!root) return {};
  queue<TreeNode*> q1, q2;
  TreeNode* cur;
  q1.push(root);
  vector<vector<int>> ans;
  vector<int> tmp;
  while (q1.size() > 0) {
    cur = q1.front();
    q1.pop();
    tmp.push_back(cur->val);
    if (cur->left) q2.push(cur->left);
    if (cur->right) q2.push(cur->right);
    if (q1.size() == 0 && q2.size() > 0) {
      swap(q1, q2);
      ans.push_back(tmp);
      tmp.clear();
    }
  }
  if (tmp.size() > 0) ans.push_back(tmp);
  return ans;
}

int main() {}