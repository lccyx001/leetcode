#include "common.hh"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
 public:
  void dfs(TreeNode* root) {
    if (!root) return;
    dfs(root->left);
    root_queue.push(root);
    dfs(root->right);
  }
  BSTIterator(TreeNode* root) { dfs(root); }

  int next() {
    int ans = root_queue.front()->val;
    root_queue.pop();
    return ans;
  }

  bool hasNext() { return root_queue.size() > 0; }

 private:
  queue<TreeNode*> root_queue;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */