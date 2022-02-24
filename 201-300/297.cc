#include "common.hh"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) return "n";
    string ser = "p:" + to_string(root->val) + "l:" + serialize(root->left) +
                 "r:" + serialize(root->right);
    return ser;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.size() <= 1) return nullptr;
    int n = data.size();
    stack<TreeNode*> sta;
    TreeNode* root = new TreeNode(0);
    sta.push(root);
    for (int i = 0; i < n; i++) {
      if (data[i] == 'n') {
        i++;
        continue;
      }
      if (data[i] == 'p') {
        i += 2;
        TreeNode* cur = sta.top();
        cur->val = data[i] - '0';
      }
    }

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));