#include "common.hh"
using namespace std;

Node* connect(Node* root) {
  if (!root) return root;
  queue<Node*> q1, q2;
  q1.push(root);
  Node *cur, *pre;
  while (q1.size() > 0) {
    cur = q1.front();
    q1.pop();
    if (cur->left) q2.push(cur->left);
    if (cur->right) q2.push(cur->right);
    if (q1.size() == 0) {
      cur->next = nullptr;
      swap(q1, q2);
    } else {
      cur->next = q1.front();
    }
  }
  return root;
}