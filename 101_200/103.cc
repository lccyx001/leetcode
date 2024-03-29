#include "../common.hh"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
  if (!root) return {};
  queue<TreeNode*> q1, q2;
  TreeNode* cur;
  q1.push(root);
  int level = 1;
  vector<vector<int>> ans;
  vector<int> tmp;
  while (q1.size() > 0) {
    cur = q1.front();
    q1.pop();
    tmp.push_back(cur->val);
    if (cur->left) q2.push(cur->left);
    if (cur->right) q2.push(cur->right);
    if (q1.size() == 0) {
      swap(q1, q2);
      if (level % 2 == 1) reverse(tmp.begin(), tmp.end());
      ans.push_back(tmp);
      tmp.clear();
      level++;
    }
  }
  if (tmp.size() > 0) {
    if (level % 2 == 1) reverse(tmp.begin(), tmp.end());
    ans.push_back(tmp);
  }
  return ans;
}

int main() {}